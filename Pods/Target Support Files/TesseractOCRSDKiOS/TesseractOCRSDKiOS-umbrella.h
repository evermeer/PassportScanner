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

#import "MGConstants.h"
#import "MGRecognitionOperation.h"
#import "MGRecognizedBlock.h"
#import "MGTesseract.h"
#import "MGTesseractDelegate.h"
#import "MGTesseractParameters.h"
#import "TesseractOCRSDKiOS.h"
#import "UIImage+Filters.h"

FOUNDATION_EXPORT double TesseractOCRSDKiOSVersionNumber;
FOUNDATION_EXPORT const unsigned char TesseractOCRSDKiOSVersionString[];

