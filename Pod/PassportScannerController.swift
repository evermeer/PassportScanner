//
//  PassportScannerController.swift
//
//  Created by Edwin Vermeer on 9/7/15.
//  Copyright (c) 2015. All rights reserved.
//

import Foundation

import UIKit

public class PassportScannerController: UIViewController {

    /// Set debug to true if you want to see what's happening
    public var debug = false
    /// Set accuracy that is required for the scan. 1 = all checksums should be ok
    public var accuracy:Float = 1
    /// When you create your own view, then make sure you have a GPUImageView that is linked to this
    @IBOutlet var filterView: GPUImageView!
    
    ///  wait a fraction of a second between scans to give the system time to handle things.
    var timer: NSTimer? //

    /// For capturing the video and passing it on to the filters.
    private let videoCamera: GPUImageVideoCamera
    
    // Quick reference to the used filter configurations
    var exposure = GPUImageExposureFilter()
    var highlightShadow = GPUImageHighlightShadowFilter()
    var saturation = GPUImageSaturationFilter()
    var contrast = GPUImageContrastFilter()
    var adaptiveTreshold = GPUImageAdaptiveThresholdFilter()
    var crop = GPUImageCropFilter()
    var averageColor = GPUImageAverageColor()
    
    /// The tesseract OCX engine
    var tesseract:G8Tesseract = G8Tesseract(language: "eng")
    
    /**
    Initializer that will initialize the video camera forced to portait mode
    
    :param: aDecoder the NSCOder
    
    :returns: instance of this controller
    */
    public required init?(coder aDecoder: NSCoder) {
        videoCamera = GPUImageVideoCamera(sessionPreset: AVCaptureSessionPreset1920x1080, cameraPosition: .Back)
        videoCamera.outputImageOrientation = .Portrait;
        super.init(coder: aDecoder)
    }
    
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
        
        // Filter settings
        exposure.exposure = 0.8 // -10 - 10
        highlightShadow.highlights  = 0.7 // 0 - 1
        saturation.saturation  = 0.3 // 0 - 2
        contrast.contrast = 3.0  // 0 - 4
        adaptiveTreshold.blurRadiusInPixels = 8.0
        
        // Only use this area for the OCR
        crop.cropRegion = CGRectMake(350.0/1080.0, 110.0/1920.0, 350.0/1080, 1700.0/1920.0)
        
        // Try to dinamically optimize the exposure based on the average color
        averageColor.colorAverageProcessingFinishedBlock = {(redComponent, greenComponent, blueComponent, alphaComponent, frameTime) in
            let lighting = redComponent + greenComponent + blueComponent
            let currentExposure = self.exposure.exposure
            // The stablil color is between 2.85 and 2.91. Otherwise change the exposure
            if lighting < 2.85 {
                self.exposure.exposure = currentExposure + (2.88 - lighting) * 2
            }
            if lighting > 2.91 {
                self.exposure.exposure = currentExposure - (lighting - 2.88) * 2
            }
        }

        // Chaining the filters
        videoCamera.addTarget(exposure)
        exposure.addTarget(highlightShadow)
        highlightShadow.addTarget(saturation)
        saturation.addTarget(contrast)
        contrast.addTarget(self.filterView)
        
        // Strange! Adding this filter will give a great readable picture, but the OCR won't work.
        // contrast.addTarget(adaptiveTreshold)
        // adaptiveTreshold.addTarget(self.filterView)
        
        // Adding these 2 extra filters to automatically control exposure depending of the average color in the scan area
        contrast.addTarget(crop)
        crop.addTarget(averageColor)
        
        self.view.backgroundColor = UIColor.whiteColor()
    }
    
    /**
    call this from your code to start a scan immediately or hook it to a button.
    
    :param: sender The sender of this event
    */
    @IBAction public func StartScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.blackColor()
        
        self.videoCamera.startCameraCapture()
        self.timer = NSTimer.scheduledTimerWithTimeInterval(0.02, target: self, selector: Selector("scan"), userInfo: nil, repeats: false)
    }
    
    /**
    call this from your code to stop a scan or hook it to a button
    
    :param: sender the sender of this event
    */
    @IBAction public func StopScan(sender: AnyObject) {
        self.view.backgroundColor = UIColor.whiteColor()
        self.videoCamera.stopCameraCapture()
        timer?.invalidate()
        timer = nil
        abbortScan()
    }
    
    /**
    Perform a scan
    */
    public func scan() {
        self.timer?.invalidate()
        self.timer = nil

        print("Start OCR")

        // Get a snapshot from this filter, should be from the next runloop
        let currentFilterConfiguration = contrast
        currentFilterConfiguration.useNextFrameForImageCapture()
        NSOperationQueue.mainQueue().addOperationWithBlock {
            let snapshot = currentFilterConfiguration.imageFromCurrentFramebuffer()
            if snapshot == nil {
                print("- Could not get snapshot from camera")
                self.StartScan(self)
                return
            }
            
            print("- Could get snapshot from camera")
            
            var result:String?
            
            autoreleasepool {
                // Crop scan area
                let cropRect:CGRect! = CGRect(x: 350,y: 110,width: 350, height: 1700)
                let imageRef:CGImageRef! = CGImageCreateWithImageInRect(snapshot.CGImage, cropRect);
                //let croppedImage:UIImage = UIImage(CGImage: imageRef)
               
                // Four times faster scan speed when the image is smaller. Another bennefit is that the OCR results are better at this resolution
                let croppedImage:UIImage =   UIImage(CGImage: imageRef).resizedImageToFitInSize(CGSize(width: 350 * 0.5 , height: 1700 * 0.5 ), scaleIfSmaller: true)

                
                // Rotate cropped image
                let selectedFilter = GPUImageTransformFilter()
                selectedFilter.setInputRotation(kGPUImageRotateLeft, atIndex: 0)
                let image:UIImage = selectedFilter.imageByFilteringImage(croppedImage)
                
                // Start OCR
                // download traineddata to tessdata folder for language from:
                // https://code.google.com/p/tesseract-ocr/downloads/list
                // ocr traineddata ripped from:
                // http://getandroidapp.org/applications/business/79952-nfc-passport-reader-2-0-8.html
                // see http://www.sk-spell.sk.cx/tesseract-ocr-en-variables
                self.tesseract.setVariableValue("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ<", forKey: "tessedit_char_whitelist");
                self.tesseract.setVariableValue("FALSE", forKey: "x_ht_quality_check")
                self.tesseract.image = image
                print("- Start recognize")
                self.tesseract.recognize()
                result = self.tesseract.recognizedText
                //tesseract = nil
                G8Tesseract.clearCache()
            }
            
            print("Scanresult : \(result)")
            
            // Perform OCR
            if let r = result {
                let mrz = MRZ(scan: r, debug: self.debug)
                if  mrz.isValid < self.accuracy {
                    print("Scan quality insufficient : \(mrz.isValid)")
                } else {
                    self.videoCamera.stopCameraCapture()
                    self.succesfullScan(mrz)
                    return
                }
            }
            self.StartScan(self)

        }
    }

    /**
    Override this function in your own class for processing the result
    
    :param: mrz The MRZ result
    */
    public func succesfullScan(mrz:MRZ) {
        assertionFailure("You should overwrite this function to handle the scan results")
    }
    
    /**
    Override this function in your own class for processing a cancel
    */
    public func abbortScan() {
        assertionFailure("You should overwrite this function to handle the scan results")
    }
    
    
}