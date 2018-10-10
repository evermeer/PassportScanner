//
//  MGRecognitionOperation.m
//  Tesseract OCR iOS
//
//  Created by Mister Grizzly on 2018.
//  Copyright (c) 2018 Mister Grizzly - www.mistergrizzly.com. All rights reserved.
//

#import "MGRecognitionOperation.h"
#import "TesseractOCRSDKiOS.h"

@interface MGRecognitionOperation() <MGTesseractDelegate> {
    MGTesseract *_tesseract;
}
@property (nonatomic, assign, readwrite) CGFloat progress;

@end

@implementation MGRecognitionOperation

- (id) initWithLanguage:(NSString *)language
{
    self = [super init];
    if (self != nil) {
        _tesseract = [[MGTesseract alloc] initWithLanguage:language];
        _tesseract.delegate = self;

        __weak __typeof(self) weakSelf = self;
        self.completionBlock = ^{
            __strong __typeof(weakSelf) strongSelf = weakSelf;

            MGRecognitionOperationCallback callback = [strongSelf.recognitionCompleteBlock copy];
            MGTesseract *tesseract = strongSelf.tesseract;
            if (callback != nil) {
                [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                    callback(tesseract);
                }];
            }
        };
    }
    return self;
}

- (void)main
{
    @autoreleasepool {
        // Analyzing the layout must be performed before recognition
        [self.tesseract analyseLayout];
        
        [self.tesseract recognize];
    }
}

- (void)progressImageRecognitionForTesseract:(MGTesseract *)tesseract
{
    self.progress = self.tesseract.progress / 100.0f;

    if (self.progressCallbackBlock != nil) {
        self.progressCallbackBlock(self.tesseract);
    }

    if ([self.delegate respondsToSelector:@selector(progressImageRecognitionForTesseract:)]) {
        [self.delegate progressImageRecognitionForTesseract:tesseract];
    }
}

- (BOOL)shouldCancelImageRecognitionForTesseract:(MGTesseract *)tesseract
{
    BOOL canceled = self.isCancelled;
    if (canceled == NO && [self.delegate respondsToSelector:@selector(shouldCancelImageRecognitionForTesseract:)]) {
        canceled = [self.delegate shouldCancelImageRecognitionForTesseract:tesseract];
    }
    return canceled;
}

- (UIImage *)preprocessedImageForTesseract:(MGTesseract *)tesseract sourceImage:(UIImage *)sourceImage
{
    if ([self.delegate respondsToSelector:@selector(preprocessedImageForTesseract:sourceImage:)]) {
        return [self.delegate preprocessedImageForTesseract:tesseract sourceImage:sourceImage];
    }
    return nil;
}

@end
