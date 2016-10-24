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

public class PassportScannerController: UIViewController, G8TesseractDelegate {

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

    :returns: Returns .portrait
    */
    override public var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        get { return .portrait }
    }
    /**
    Hide the status bar during scan

    :returns: true to indicate the statusbar should be hidden
    */
    override public var prefersStatusBarHidden: Bool {
        get { return true }
    }
    
    /**
    Initialize all graphic filters in the viewDidLoad
    */
    public override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.white

       // Filter settings
        exposure.exposure = 0.8 // -10 - 10
        highlightShadow.highlights  = 0.7 // 0 - 1
        saturation.saturation  = 0.4 // 0 - 2
        contrast.contrast = 2.0  // 0 - 4
        adaptiveTreshold.blurRadiusInPixels = 8.0

        // Specify the crop region that will be used for the OCR
        crop.cropSizeInPixels = Size(width: 350, height: 1800)
        crop.locationOfCropInPixels = Position(350, 60, nil)
        crop.overriddenOutputRotation = .rotateClockwise

        // Try to dinamically optimize the exposure based on the average color
        averageColor.extractedColorCallback = { color in
            let lighting = color.blueComponent + color.greenComponent + color.redComponent
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
            if self.exposure.exposure < -3 {
                self.exposure.exposure = -3
            }
        }

        // Initialize the camera and chain the filters
        do {
            camera = try Camera(sessionPreset:AVCaptureSessionPreset1920x1080)
            camera.location = PhysicalCameraLocation.backFacing

            camera --> exposure --> highlightShadow --> saturation --> contrast --> adaptiveTreshold --> renderView
            adaptiveTreshold --> crop --> averageColor
        } catch {
            fatalError("Could not initialize rendering pipeline: \(error)")
        }

        // download traineddata to tessdata folder for language from:
        // https://code.google.com/p/tesseract-ocr/downloads/list
        // ocr traineddata can be retreived from: :)
        // http://getandroidapp.org/applications/business/79952-nfc-passport-reader-2-0-8.html
        // optimisations created based on https://github.com/gali8/Tesseract-OCR-iOS/wiki/Tips-for-Improving-OCR-Results
        
        // tesseract OCR settings
        self.tesseract.setVariableValue("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ<", forKey: "tessedit_char_whitelist")
        self.tesseract.delegate = self
        self.tesseract.rect = CGRect(x: 0, y: 0, width: 900, height: 175)

        // see http://www.sk-spell.sk.cx/tesseract-ocr-en-variables
        self.tesseract.setVariableValue("1", forKey: "tessedit_serial_unlv")
        self.tesseract.setVariableValue("FALSE", forKey: "x_ht_quality_check")
/*
        self.tesseract.setVariableValue("FALSE", forKey: "load_system_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_freq_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_unambig_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_punc_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_number_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "load_fixed_length_dawgs")
        self.tesseract.setVariableValue("FALSE", forKey: "load_bigram_dawg")
        self.tesseract.setVariableValue("FALSE", forKey: "wordrec_enable_assoc")
*/
    }

    
    public func preprocessedImage(for tesseract: G8Tesseract!, sourceImage: UIImage!) -> UIImage! {
        // sourceImage is the same image you sent to Tesseract above. 
        // Processing is already done in dynamic filters    
        return sourceImage
    }
    
    
    /**
    call this from your code to start a scan immediately or hook it to a button.

    :param: sender The sender of this event
    */
    @IBAction public func StartScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.black
        camera.startCapture()

        DispatchQueue.main.asyncAfter(deadline: .now() + 0.2) {
            //TODO: fix this - Testing versions.
            self.scanV1()
                // only the 1/2 of the image will be processed by tesseract

            //self.scanV2()
                // image will be on disc (possible security issue)
                // only the 1/2 of the image will be processed by tesseract
        }
    }

    /**
    call this from your code to stop a scan or hook it to a button

    :param: sender the sender of this event
    */
    @IBAction public func StopScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.white
        camera.stopCapture()
        abbortScan()
    }


    /**
     Perform a scan using PictureOutput
     */
    public func scanV1() {
        // This version is not good. It will crash regulary and only the 1/2 of the image will be processed by tesseract
        print("Start OCR")

        pictureOutput = PictureOutput()
        pictureOutput.encodedImageFormat = .png
        pictureOutput.onlyCaptureNextFrame = true
        pictureOutput.imageAvailableCallback = { sourceImage in
            if self.processImage(sourceImage: sourceImage) { return }

            // Not successfull, start another scan
            self.StartScan(sender: self)
        }
        self.crop --> pictureOutput
    }

    /**
    Perform a scan using save to file
    */
    public func scanV2() {
        print("Start OCR")
        // This version of is not good. The image will be on disc (possible security issue) and still only half the image will be processed by tesseract.
        // Instead of using the PictureOutput (prefered way) we will write an load the image from disk
        let path = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)[0] as String
        let imagePath = NSURL(fileURLWithPath: path).appendingPathComponent("temp.png")
        self.crop.saveNextFrameToURL(imagePath!, format: .png)
        if let sourceImage: UIImage = UIImage(data: (NSData(contentsOf:(imagePath)!) ?? NSData()) as Data) {
            if self.processImage(sourceImage: sourceImage) { return }
        }
        // Not successfull, start another scan
        self.StartScan(sender: self)
    }

    /**
     Processing the image

     - parameter sourceImage: The image that needs to be processed
     */
    public func processImage(sourceImage: UIImage) -> Bool {
        // resize image. Smaller images are faster to process. When letters are too big the scan quality goes down.
        let croppedImage: UIImage = sourceImage.resizedImageToFit(in: CGSize(width: 350 * 0.5, height: 1800 * 0.5), scaleIfSmaller: true)
        
        // rotate image. tesseract needs the correct orientation.
        let image: UIImage = croppedImage.rotate(by: -90)!
        
        // Perform the OCR scan
        let result: String = self.doOCR(image: image)

        // Create the MRZ object and validate if it's OK
        let mrz = MRZ(scan: result, debug: self.debug)
        if  mrz.isValid < self.accuracy {
            print("Scan quality insufficient : \(mrz.isValid)")
        } else {
            self.camera.stopCapture()
            self.succesfullScan(mrz: mrz)
            return true
        }
        return false
    }

    /**
     Perform the tesseract OCR on an image.

     - parameter image: The image to be scanned

     - returns: The OCR result
     */
    public func doOCR(image: UIImage) -> String {
        // Start OCR
        var result: String?
        self.tesseract.image = image
        print("- Start recognize")
        self.tesseract.recognize()
        result = self.tesseract.recognizedText
        //tesseract = nil
        G8Tesseract.clearCache()
        print("Scanresult : \(result)")
        return result ?? ""
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

@available(iOS 10.0, *)
extension UIImage {
    func rotate(by degrees: Double) -> UIImage? {
        guard let cgImage = self.cgImage else { return nil }
        
        let transform = CGAffineTransform(rotationAngle: CGFloat(degrees * .pi / 180.0))
        var rect = CGRect(origin: .zero, size: self.size).applying(transform)
        rect.origin = .zero
        
        let renderer = UIGraphicsImageRenderer(size: rect.size)
        return renderer.image { renderContext in
            renderContext.cgContext.translateBy(x: rect.midX, y: rect.midY)
            renderContext.cgContext.rotate(by: CGFloat(degrees * .pi / 180.0))
            renderContext.cgContext.scaleBy(x: 1.0, y: -1.0)
            
            let drawRect = CGRect(origin: CGPoint(x: -self.size.width/2, y: -self.size.height/2), size: self.size)
            renderContext.cgContext.draw(cgImage, in: drawRect)
        }
    }
}
