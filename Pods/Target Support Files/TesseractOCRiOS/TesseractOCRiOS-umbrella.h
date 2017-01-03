#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "G8Constants.h"
#import "G8RecognitionOperation.h"
#import "G8RecognizedBlock.h"
#import "G8Tesseract.h"
#import "G8TesseractDelegate.h"
#import "G8TesseractParameters.h"
#import "TesseractOCR.h"
#import "UIImage+G8Filters.h"
#import "UIImage+G8FixOrientation.h"

FOUNDATION_EXPORT double TesseractOCRVersionNumber;
FOUNDATION_EXPORT const unsigned char TesseractOCRVersionString[];

