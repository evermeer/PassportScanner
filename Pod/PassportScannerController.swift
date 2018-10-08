//
//  PassportScannerController.swift
//
//  Created by Edwin Vermeer on 9/7/15.
//  Copyright (c) 2015. All rights reserved.
//

import ImageDetect
import SwiftOCR
 
import Foundation
import UIKit
import TesseractOCR
import EVGPUImage2
import GPUImage //Still using this for the rotate
import UIImage_Resize
import AVFoundation

open class PassportScannerController: UIViewController, G8TesseractDelegate {

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

    let swiftOCRInstance = SwiftOCR()
    
    /**
    Rotation is not needded.

    :returns: Returns .portrait
    */
    override open var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        get { return .portrait }
    }
    /**
    Hide the status bar during scan

    :returns: true to indicate the statusbar should be hidden
    */
    override open var prefersStatusBarHidden: Bool {
        get { return true }
    }
    
    /**
    Initialize all graphic filters in the viewDidLoad
    */
    open override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.white

       // Filter settings
        exposure.exposure = 0.7 // -10 - 10
        highlightShadow.highlights  = 0.6 // 0 - 1
        saturation.saturation  = 0.6 // 0 - 2
        contrast.contrast = 2.0  // 0 - 4
        adaptiveTreshold.blurRadiusInPixels = 8.0

        // Specify the crop region that will be used for the OCR
        crop.cropSizeInPixels = Size(width: 350, height: 1800)
        crop.locationOfCropInPixels = Position(350, 60, nil)
        crop.overriddenOutputRotation = .rotateClockwise

        // Try to dynamically optimize the exposure based on the average color
        averageColor.extractedColorCallback = { color in
            let lighting = color.blueComponent + color.greenComponent + color.redComponent
            let currentExposure = self.exposure.exposure
            // The stablil color is between 2.75 and 2.85. Otherwise change the exposure
            if lighting < 2.75 {
                self.exposure.exposure = currentExposure + (2.80 - lighting) * 2
            }
            if lighting > 2.85 {
                self.exposure.exposure = currentExposure - (lighting - 2.80) * 2
            }
            if self.exposure.exposure > 2 {
                self.exposure.exposure = 2
            }
            if self.exposure.exposure < -2 {
                self.exposure.exposure = -2
            }
        }

        // download traineddata to tessdata folder for language from:
        // https://code.google.com/p/tesseract-ocr/downloads/list
        // ocr traineddata is available in:    ;)
        // http://getandroidapp.org/applications/business/79952-nfc-passport-reader-2-0-8.html
        // optimisations created based on https://github.com/gali8/Tesseract-OCR-iOS/wiki/Tips-for-Improving-OCR-Results
        
        // tesseract OCR settings
        self.tesseract.setVariableValue("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ<", forKey: "tessedit_char_whitelist")
        self.tesseract.delegate = self
        self.tesseract.rect = CGRect(x: 0, y: 0, width: 900, height: 175)

        // see http://www.sk-spell.sk.cx/tesseract-ocr-en-variables
        self.tesseract.setVariableValue("1", forKey: "tessedit_serial_unlv")
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

    open override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        do {
            // Initialize the camera
            camera = try Camera(sessionPreset:AVCaptureSessionPreset1920x1080)
            camera.location = PhysicalCameraLocation.backFacing
            
            // Chain the filter to the render view
            camera --> exposure  --> highlightShadow  --> saturation --> contrast --> adaptiveTreshold --> renderView
            
            // Use the same chained filters and forward these to 2 other filters
            adaptiveTreshold --> crop --> averageColor
        } catch {
            fatalError("Could not initialize rendering pipeline: \(error)")
        }
    }
    
    open func preprocessedImage(for tesseract: G8Tesseract!, sourceImage: UIImage!) -> UIImage! {
        // sourceImage is the same image you sent to Tesseract above. 
        // Processing is already done in dynamic filters    
        return sourceImage
    }
    
    
    /**
    call this from your code to start a scan immediately or hook it to a button.

    :param: sender The sender of this event
    */
    @IBAction open func StartScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.black
        camera.startCapture()

        DispatchQueue.main.asyncAfter(deadline: .now() + 0.2) {
            print("Start OCR")
            
            self.pictureOutput = PictureOutput()
            self.pictureOutput.encodedImageFormat = .png
            self.pictureOutput.onlyCaptureNextFrame = true
            self.pictureOutput.imageAvailableCallback = { sourceImage in
                if self.processImage(sourceImage: sourceImage) { return }
                
                // Not successfull, start another scan
                self.StartScan(sender: self)
            }
            self.crop --> self.pictureOutput
        }
    }

    /**
    call this from your code to stop a scan or hook it to a button

    :param: sender the sender of this event
    */
    @IBAction open func StopScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.white
        camera.stopCapture()
        abbortScan()
    }



    /**
     Processing the image

     - parameter sourceImage: The image that needs to be processed
     */
    open func processImage(sourceImage: UIImage) -> Bool {
        
        // Rotate cropped image
        //let selectedFilter1 = GPUImageTransformFilter()
        //selectedFilter1.setInputRotation(kGPUImageRotateLeft, at: 0)
        //let si: UIImage = selectedFilter1.image(byFilteringImage: sourceImage)
        let si: UIImage = sourceImage.rotate(by: -90)!
        
        si.detector.crop(type: .text) { [weak self] result in
            switch result {
            case .success(let croppedImages):
                let lines: [String] = []
                for image in croppedImages {
                    swiftOCRInstance.recognize(image) { recognizedString in
                        if recognizedString.length == 40 {
                            lines.append(recognizedString)
                        }
                    }
                }
                print(lines)
            case .notFound:
                print("Not Found")
            case .failure(let error):
                print(error.localizedDescription)
            }
        }
        
        
        // Perform the OCR scan
        let result: String = self.doOCR(image: si)

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
    open func doOCR(image: UIImage) -> String {
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
    open func succesfullScan(mrz: MRZ) {
        assertionFailure("You should overwrite this function to handle the scan results")
    }

    /**
    Override this function in your own class for processing a cancel
    */
    open func abbortScan() {
        assertionFailure("You should overwrite this function to handle an aabbort")
    }

}


// Wanted to use this rotation function. Tesseract does not like the result image. Went back to GpuImage for the rotation. Will try again later so that we can remove the old GpuImage dependency
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
