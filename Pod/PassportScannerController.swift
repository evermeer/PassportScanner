//
//  PassportScannerController.swift
//
//  Created by Edwin Vermeer on 9/7/15.
//  Copyright (c) 2015. All rights reserved.
//

import Foundation
import UIKit
import TesseractOCR
import GPUImage2
import UIImage_Resize
import AVFoundation

public class PassportScannerController: UIViewController {

    /// Set debug to true if you want to see what's happening
    public var debug = false

    /// Set accuracy that is required for the scan. 1 = all checksums should be ok
    public var accuracy: Float = 1

    /// When you create your own view, then make sure you have a GPUImageView that is linked to this
    @IBOutlet var renderView: RenderView!

    /// For capturing the video and passing it on to the filters.
    var camera: Camera!

    // Quick reference to the used filter configurations
    var exposure = ExposureAdjustment()
    var highlightShadow = HighlightsAndShadows()
    var saturation = SaturationAdjustment()
    var contrast = ContrastAdjustment()
    var adaptiveTreshold = AdaptiveThreshold()
    var crop = Crop()
    var averageColor = AverageColorExtractor()

    var pictureOutput = PictureOutput()

    /// The tesseract OCX engine
    var tesseract: G8Tesseract = G8Tesseract(language: "eng")

    /**
    Rotation is not needded.

    :returns: Returns .Portrait
    */
    public override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return UIInterfaceOrientationMask.Portrait
    }

    /**
    Hide the status bar during scan

    :returns: true to indicate the statusbar should be hidden
    */
    public override func prefersStatusBarHidden() -> Bool {
        return true
    }

    /**
    Initialize all graphic filters in the viewDidLoad
    */
    public override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.whiteColor()

        // Filter settings
        exposure.exposure = 0.8 // -10 - 10
        highlightShadow.highlights  = 0.7 // 0 - 1
        saturation.saturation  = 0.4 // 0 - 2
        contrast.contrast = 2.0  // 0 - 4
        adaptiveTreshold.blurRadiusInPixels = 8.0

        // Specify the crop region that will be used for the OCR
        crop.cropSizeInPixels = Size(width: 350, height: 1700)
        crop.locationOfCropInPixels = Position(350, 110, nil)
        crop.overriddenOutputRotation = .RotateClockwise

        // Try to dinamically optimize the exposure based on the average color
        averageColor.extractedColorCallback = { color in
            let lighting = color.blue + color.green + color.red
            let currentExposure = self.exposure.exposure
            // The stablil color is between 2.85 and 2.91. Otherwise change the exposure
            if lighting < 2.85 {
                self.exposure.exposure = currentExposure + (2.88 - lighting) * 2
            }
            if lighting > 2.91 {
                self.exposure.exposure = currentExposure - (lighting - 2.88) * 2
            }
            if self.exposure.exposure > 3 {
                self.exposure.exposure = 3
            }
        }

        // Initialize the camera and chain the filters
        do {
            camera = try Camera(sessionPreset:AVCaptureSessionPreset1920x1080)
            camera.location = PhysicalCameraLocation.BackFacing

            camera --> exposure --> highlightShadow --> saturation --> contrast --> adaptiveTreshold --> renderView
            adaptiveTreshold --> crop --> averageColor
        } catch {
            fatalError("Could not initialize rendering pipeline: \(error)")
        }

        // download traineddata to tessdata folder for language from:
        // https://code.google.com/p/tesseract-ocr/downloads/list
        // ocr traineddata ripped from:
        // http://getandroidapp.org/applications/business/79952-nfc-passport-reader-2-0-8.html
        // see http://www.sk-spell.sk.cx/tesseract-ocr-en-variables

        // tesseract OCR settings
        self.tesseract.setVariableValue("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ<", forKey: "tessedit_char_whitelist")
        self.tesseract.setVariableValue("FALSE", forKey: "x_ht_quality_check")
        self.tesseract.setVariableValue("FALSE", forKey: "load_system_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_freq_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_unambig_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_punc_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_number_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_fixed_length_dawgs")
        self.tesseract.setVariableValue("FALSE", forKey: "load_bigram_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "wordrec_enable_assoc")

    }

    /**
    call this from your code to start a scan immediately or hook it to a button.

    :param: sender The sender of this event
    */
    @IBAction public func StartScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.blackColor()
        camera.startCapture()

        let dispatchTime: dispatch_time_t = dispatch_time(DISPATCH_TIME_NOW, Int64(0.2 * Double(NSEC_PER_SEC)))
        dispatch_after(dispatchTime, dispatch_get_main_queue(), {
            self.scan()
        })
    }

    /**
    call this from your code to stop a scan or hook it to a button

    :param: sender the sender of this event
    */
    @IBAction public func StopScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.whiteColor()
        camera.stopCapture()
        abbortScan()
    }

    /**
    Perform a scan
    */
    public func scan() {
        print("Start OCR")

        pictureOutput = PictureOutput()
        pictureOutput.encodedImageFormat = .JPEG
        pictureOutput.onlyCaptureNextFrame = true
        pictureOutput.imageAvailableCallback = { sourceImage in
            var result: String?

            // resize image. Smaller images are faster to process. When letters are too big the scan quality goes down.
            let croppedImage: UIImage = sourceImage.resizedImageToFitInSize(CGSize(width: 350 * 0.5, height: 1700 * 0.5), scaleIfSmaller: true)

            // rotate image. tesseract needs the correct orientation.
            let image: UIImage = croppedImage.rotate(byDegrees: -90, toSize: CGSize(width: croppedImage.size.height, height: croppedImage.size.width))

            // Start OCR
            self.tesseract.image = image
            print("- Start recognize")
            self.tesseract.recognize()
            result = self.tesseract.recognizedText
            //tesseract = nil
            G8Tesseract.clearCache()
            print("Scanresult : \(result)")

            // Validate the MRZ
            if let r = result {
                let mrz = MRZ(scan: r, debug: self.debug)
                if  mrz.isValid < self.accuracy {
                    print("Scan quality insufficient : \(mrz.isValid)")
                } else {
                    self.camera.stopCapture()
                    self.succesfullScan(mrz)
                    return
                }
            }
            self.StartScan(self)

        }
        self.crop --> pictureOutput
    }

    /**
    Override this function in your own class for processing the result

    :param: mrz The MRZ result
    */
    public func succesfullScan(mrz: MRZ) {
        assertionFailure("You should overwrite this function to handle the scan results")
    }

    /**
    Override this function in your own class for processing a cancel
    */
    public func abbortScan() {
        assertionFailure("You should overwrite this function to handle the scan results")
    }

}

extension UIImage {

    func rotate(byDegrees degree: Double, toSize: CGSize? = nil) -> UIImage {
        let rotatedSize = toSize ?? self.size
        let radians = CGFloat(degree*M_PI)/180.0 as CGFloat
        let scale = UIScreen.mainScreen().scale
        UIGraphicsBeginImageContextWithOptions(rotatedSize, false, scale)
        let bitmap = UIGraphicsGetCurrentContext()
        CGContextTranslateCTM(bitmap, rotatedSize.width / 2, rotatedSize.height / 2)
        CGContextRotateCTM(bitmap, radians)
        CGContextScaleCTM(bitmap, 1.0, -1.0)
        CGContextDrawImage(bitmap, CGRectMake(-self.size.width / 2, -self.size.height / 2 , self.size.width, self.size.height), self.CGImage )
        let newImage = UIGraphicsGetImageFromCurrentImageContext()

        return newImage
    }
}
