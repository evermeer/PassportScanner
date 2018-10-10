//
//  MGTesseractDelegate.h
//  Tesseract OCR iOS
//
//
//  Created by Mister Grizzly on 2018.
//  Copyright (c) 2018 Mister Grizzly - www.mistergrizzly.com. All rights reserved.
//

#ifndef Tesseract_OCR_iOS_MGTesseractDelegate_h
#define Tesseract_OCR_iOS_MGTesseractDelegate_h

@class MGTesseract;
@class UIImage;

/**
 *  `MGTesseractDelegate` provides delegate methods for Tesseract recognition.
 */
@protocol MGTesseractDelegate <NSObject>

@optional

/**
 *  An optional method to be called periodically during recognition so
 *  the recognition's progress can be observed.
 *
 *  @param tesseract The `MGTesseract` object performing the recognition.
 */
- (void)progressImageRecognitionForTesseract:(MGTesseract *)tesseract;

/**
 *  An optional method to be called periodically during recognition so
 *  the user can choose whether or not to cancel recognition.
 *
 *  @param tesseract The `MGTesseract` object performing the recognition.
 *
 *  @return Whether or not to cancel the recognition in progress.
 */
- (BOOL)shouldCancelImageRecognitionForTesseract:(MGTesseract *)tesseract;

/**
 *  An optional method to provide image preprocessing. To perform default
 *  Tesseract preprocessing return `nil` in this method.
 *
 *  @param tesseract   The `MGTesseract` object performing the recognition.
 *  @param sourceImage The source `UIImage` to perform preprocessing.
 *
 *  @return Preprocessed `UIImage` or nil to perform default preprocessing.
 */
- (UIImage *)preprocessedImageForTesseract:(MGTesseract *)tesseract sourceImage:(UIImage *)sourceImage;

@end

#endif
