//
//  RecognitionOperation.h
//  Tesseract OCR iOS
//
//
//  Created by Mister Grizzly on 2018.
//  Copyright (c) 2018 Mister Grizzly - www.mistergrizzly.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MGTesseract.h"

/**
 *  The type of a block function that can be used as a callback for the
 *  recognition operation.
 *
 *  @param tesseract The `MGTesseract` object performing the recognition.
 */
typedef void(^MGRecognitionOperationCallback)(MGTesseract *tesseract);

/**
 *  `MGRecognitionOperation` is a convenience class for recognizing and 
 *  analyzing text in images asynchronously using `NSOperation`.
 */
@interface MGRecognitionOperation : NSOperation

/**
 *  The `MGTesseract` object performing the recognition.
 */
@property (nonatomic, strong, readonly) MGTesseract *tesseract;

/**
 *  An optional delegate for Tesseract's recognition.
 *
 *  @note Delegate methods will be called from operation thread.
 */
@property (nonatomic, weak) id<MGTesseractDelegate> delegate;

/**
 *  The percentage of progress of Tesseract's recognition (between 0 and 100).
 */
@property (nonatomic, assign, readonly) CGFloat progress;

/**
 *  A `MGRecognitionOperationBlock` function that will be called when the
 *  recognition has been completed.
 *  
 *  @note It will be called from main thread.
 */
@property (nonatomic, copy) MGRecognitionOperationCallback recognitionCompleteBlock;

/**
 *  A `MGRecognitionOperationBlock` function that will be called periodically
 *  as the recognition progresses.
 *
 *  @note It will be called from operation thread.
 */
@property (nonatomic, copy) MGRecognitionOperationCallback progressCallbackBlock;

/// The default initializer should not be used since the language Tesseract
/// uses needs to be explicit.
- (instancetype)init __attribute__((unavailable("Use initWithLanguage:language instead")));

/**
 *  Initialize a MGRecognitionOperation with the provided language.
 *
 *  @param language The language to use in recognition.
 *
 *  @return The initialized MGRecognitionOperation object, or `nil` if there 
 *          was an error.
 */
- (id)initWithLanguage:(NSString*)language;

@end
