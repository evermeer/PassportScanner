//
//  MGConstants.h
//  Tesseract OCR iOS
//
//  Created by Mister Grizzly on 2018.
//  Copyright (c) 2018 Mister Grizzly - www.mistergrizzly.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef Tesseract_OCR_iOS_MGConstants_h
#define Tesseract_OCR_iOS_MGConstants_h

#ifndef NS_DESIGNATED_INITIALIZER
#if __has_attribute(objc_designated_initializer)
#define NS_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
#else
#define NS_DESIGNATED_INITIALIZER
#endif
#endif

/**
 * Possible modes for page layout analysis.
 */
typedef NS_ENUM(NSUInteger, MGPageSegmentationMode){
    /**
     *  Orientation and script detection only.
     */
    MGPageSegmentationModeOSDOnly,
    /**
     *  Automatic page segmentation with orientation and script detection. (OSD)
     */
    MGPageSegmentationModeAutoOSD,
    /**
     *  Automatic page segmentation, but no OSD, or OCR.
     */
    MGPageSegmentationModeAutoOnly,
    /**
     *  Fully automatic page segmentation, but no OSD.
     */
    MGPageSegmentationModeAuto,
    /**
     *  Assume a single column of text of variable sizes.
     */
    MGPageSegmentationModeSingleColumn,
    /**
     *  Assume a single uniform block of vertically aligned text.
     */
    MGPageSegmentationModeSingleBlockVertText,
    /**
     *  Assume a single uniform block of text. (Default.)
     */
    MGPageSegmentationModeSingleBlock,
    /**
     *  Treat the image as a single text line.
     */
    MGPageSegmentationModeSingleLine,
    /**
     *  Treat the image as a single word.
     */
    MGPageSegmentationModeSingleWord,
    /**
     *  Treat the image as a single word in a circle.
     */
    MGPageSegmentationModeCircleWord,
    /**
     *  Treat the image as a single character.
     */
    MGPageSegmentationModeSingleChar,
    /**
     *  Find as much text as possible in no particular order.
     */
    MGPageSegmentationModeSparseText,
    /**
     *  Sparse text with orientation and script det.
     */
    MGPageSegmentationModeSparseTextOSD,
};

/**
 * When Tesseract/Cube is initialized we can choose to instantiate/load/run
 * only the Tesseract part, only the Cube part or both along with the combiner.
 */
typedef NS_ENUM(NSUInteger, MGOCREngineMode){
    /**
     *  Run Tesseract only - fastest
     */
    MGOCREngineModeTesseractOnly,
    /**
     *  Run Cube only - better accuracy, but slower
     */
    MGOCREngineModeCubeOnly,
    /**
     *  Run both and combine results - best accuracy
     */
    MGOCREngineModeTesseractCubeCombined,
//    MGOCREngineModeDefault,
};

/**
 *  Result iteration level
 */
typedef NS_ENUM(NSUInteger, MGPageIteratorLevel){
    /**
     *  Block of text/image/separator line.
     */
    MGPageIteratorLevelBlock,
    /**
     *  Paragraph within a block.
     */
    MGPageIteratorLevelParagraph,
    /**
     *  Line within a paragraph.
     */
    MGPageIteratorLevelTextline,
    /**
     *  Word within a textline.
     */
    MGPageIteratorLevelWord,
    /**
     *  Symbol/character within a word.
     */
    MGPageIteratorLevelSymbol,
};

/**
 * If you orient your head so that "up" aligns with Orientation,
 * then the characters will appear "right side up" and readable.
 *
 * In the example above, both the English and Chinese paragraphs are oriented
 * so their "up" is the top of the page (page up).  The photo credit is read
 * with one's head turned leftward ("up" is to page left).
 */
typedef NS_ENUM(NSUInteger, MGOrientation){
    MGOrientationPageUp,
    MGOrientationPageRight,
    MGOrientationPageDown,
    MGOrientationPageLeft,
};

/**
 * The grapheme clusters within a line of text are laid out logically
 * in this direction, judged when looking at the text line rotated so that
 * its Orientation is "page up".
 *
 * For English text, the writing direction is left-to-right.  For the
 * Chinese text in the above example, the writing direction is top-to-bottom.
 */
typedef NS_ENUM(NSUInteger, MGWritingDirection){
    MGWritingDirectionLeftToRight,
    MGWritingDirectionRightToLeft,
    MGWritingDirectionTopToBottom,
};

/**
 * The text lines are read in the given sequence.
 *
 * In English, the order is top-to-bottom.
 * In Chinese, vertical text lines are read right-to-left.  Mongolian is
 * written in vertical columns top to bottom like Chinese, but the lines
 * order left-to right.
 *
 * Note that only some combinations make sense.  For example,
 * WRITING_DIRECTION_LEFT_TO_RIGHT implies TEXTLINE_ORDER_TOP_TO_BOTTOM
 */
typedef NS_ENUM(NSUInteger, MGTextlineOrder) {
    MGTextlineOrderLeftToRight,
    MGTextlineOrderRightToLeft,
    MGTextlineOrderTopToBottom,
};

#endif
