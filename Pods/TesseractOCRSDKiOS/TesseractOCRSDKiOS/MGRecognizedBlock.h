//
//  MGRecognizedBlock.h
//  Tesseract OCR iOS
//
//
//  Created by Mister Grizzly on 2018.
//  Copyright (c) 2018 Mister Grizzly - www.mistergrizzly.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGConstants.h"

/**
 *  `MGRecognizedBlock` is a data structure that provides information about a
 *  recognition result at some resolution level.
 */
@interface MGRecognizedBlock : NSObject <NSCopying>

/**
 *  The text that Tesseract has recognized for this block. This string could 
 *  hold a single character, one word, or multiple words, depending on the
 *  resolution level of the block.
 */
@property (nonatomic, copy, readonly) NSString *text;

/**
 *  The normalized bounding box rectangle where this recognized block appears in the
 *  target image.
 *
 *  @note The parameters of this `CGRect` is normalized and lays in 0.0-1.0 range.
 *        If you want to get actual rectangle use `boundingBoxAtImageOfSize` with
 *        size of target image.
 */
@property (nonatomic, assign, readonly) CGRect boundingBox;

/**
 *  Tesseract's confidence in the accuracy of this recognition result. This
 *  number will be between 0.0 and 100.0.
 */
@property (nonatomic, assign, readonly) CGFloat confidence;

/**
 *  The resolution of this recognized block. See `MGPageIteratorLevel` in
 *  MGConstants.h for the different level options.
 */
@property (nonatomic, assign, readonly) MGPageIteratorLevel level;

/**
 *  Initialize a recognized block with the data it will contain.
 *
 *  @param text        The text of the result.
 *  @param boundingBox The bounding box rectangle where the result occurs in
 *                     the target image.
 *  @param confidence  The confidence (between 0.0 and 100.0) of this result.
 *  @param level       The resolution level of this result.
 *
 *  @return The initialized recognized block, or `nil` if there was an error.
 */
- (instancetype)initWithText:(NSString *)text
                 boundingBox:(CGRect)boundingBox
                  confidence:(CGFloat)confidence
                       level:(MGPageIteratorLevel)level;

/**
 *  The bounding box rectangle where this recognized block appears in the
 *  image of target size.
 *
 *  @param imageSize Size of target image.
 *
 *  @return The bounding box rectangle
 */
- (CGRect)boundingBoxAtImageOfSize:(CGSize)imageSize;

@end
