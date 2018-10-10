//
//  MGTesseract.h
//  Tesseract OCR iOS
//
//  Created by Mister Grizzly on 2018.
//  Copyright (c) 2018 Mister Grizzly - www.mistergrizzly.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGConstants.h"
#import "MGTesseractDelegate.h"

/**
 *  Default value of `sourceResolution` property.
 */
extern NSInteger const kMGDefaultResolution;

/**
 *  Minimum alowed value of `sourceResolution` property.
 */
extern NSInteger const kMGMinCredibleResolution;

/**
 *  Maximum alowed value of `sourceResolution` property.
 */
extern NSInteger const kMGMaxCredibleResolution;

/**
 *  `MGTesseract` encapsulates the Tesseract library and provides properties
 *  and methods for performing text recognition and analysis on a target image.
 */
@interface MGTesseract : NSObject

/**
 *  Returns the current version of the underlying Tesseract library.
 *
 *  @return The version string.
 */
+ (NSString *)version;

/**
 *  Clear any library-level memory caches.
 *  There are a variety of expensive-to-load constant data structures (mostly
 *  language dictionaries) that are cached globally. This function allows the
 *  clearing of these caches. It's safe to call this method, while a 
 *  recognition is in progress. It's also called automatically on 
 *  UIApplicationDidReceiveMemoryWarningNotification
 */
+ (void)clearCache;

/**
 *  The language pack to use during recognition. A corresponding trained data
 *  file must exist in the "tessdata" folder of the project. For example, if
 *  you set `language` to "foo", then "foo.traineddata" must exist in the
 *  "tessdata" folder.
 *
 *  @note   You should always check that the languages have been set correctly 
 *          and Tesseract has been configured its engine for the languages
 *          specified by `isEngineConfigured` property.
 */
@property (nonatomic, copy) NSString* language;

/**
 *  The absolute path to the tessdata folder, which may exist in either the
 *  application bundle or in the Caches directory depending on the argument to
 *  `cachesRelatedDataPath` in the designated initializer.
 */
@property (nonatomic, readonly, copy) NSString *absoluteDataPath;

/**
 *  The recognition mode to use. See `MGOCREngineMode` in MGConstants.h for the
 *  available recognition modes.
 */
@property (nonatomic, assign) MGOCREngineMode engineMode;

/**
 *  The page segmentation mode to use. See `MGPageSegmentationMode` in
 *  MGConstants.h for the available page segmentation modes.
 */
@property (nonatomic, assign) MGPageSegmentationMode pageSegmentationMode;

/**
 *  YES when Tesseract is succesfully configured, NO otherwise.
 */
@property (nonatomic, readonly, getter=isEngineConfigured) BOOL engineConfigured;

/**
 *  A white list of characters that Tesseract should recognize. Any
 *  recognition string that Tesseract returns will only contain characters from
 *  the intersection of this string and the characters Tesseract has been
 *  trained on.
 *
 *  @note It has been observed that `charWhitelist` is only respected when
 *        using the `MGOCREngineModeTesseractOnly` mode for `engineMode`.
 */
@property (nonatomic, copy) NSString *charWhitelist;

/**
 *  A black list of characters that Tesseract should not recognize. Any
 *  recognition string that Tesseract returns will not contain characters from
 *  this string.
 *
 *  @note It has been observed that `charBlacklist` is only respected when
 *        using the `MGOCREngineModeTesseractOnly` mode for `engineMode`.
 */
@property (nonatomic, copy) NSString *charBlacklist;

/**
 *  An image on which Tesseract should perform recognition.
 */
@property (nonatomic, strong) UIImage *image;

/**
 *  A rectangle to specify the region of the image on which Tesseract should
 *  limit its recognition. Change it after setting image.
 */
@property (nonatomic, assign) CGRect rect;

/**
 *  The resolution of the source image in pixels per inch so font size
 *  information can be calculated in results. It should be from 70 to
 *  2400 or it will be clamped.
 *
 *  @default Default value is 72
 */
@property (nonatomic, assign) NSUInteger sourceResolution;

/**
 *  A time limit (in seconds, via `NSTimeInterval`) to limit Tesseract's time
 *  spent during recognition.
 */
@property (nonatomic, assign) NSTimeInterval maximumRecognitionTime;

/**
 *  The percentage of progress of Tesseract's recognition (between 0 and 100).
 */
@property (nonatomic, readonly) NSUInteger progress;

/**
 *  A string of text that Tesseract has recognized from the target image.
 */
@property (nonatomic, readonly) NSString *recognizedText;

/**
 *  Make an HTML-formatted string with hOCR markup from the internal Tesseract
 *  data structures.
 *  page_number is 0-based but will appear in the output as 1-based.
 *
 *  @param pageNumber The page number within the image of interest. If you
 *                    aren't using a multipage image or don't know what this
 *                    means, use `0` for `pageNumber`.
 *
 *  @return The HTML-formatted string with hOCR markup or nil if error occured 
 *          or the engine is not properly configured.
 */
- (NSString *)recognizedHOCRForPageNumber:(int)pageNumber;

/**
 *  Produces a PDF output with the pages sent to the function
 *  @param  images  An array of the input images being recognized and 
 *                  included into the output PDF file.
 *  @return NSData  representing output PDF file or nil if error occured or
 *                  the engine is not properly configured.
 */
- (NSData *)recognizedPDFForImages:(NSArray*)images;

/**
 *  Run Tesseract's page analysis on the target image.
 *
 *  @note You must have a file called "osd.traineddata" in the "tessdata"
 *        folder to use this method. You can download this file from:
 *        https://code.google.com/p/tesseract-ocr/downloads/list
 */
- (void)analyseLayout;

/**
 *  The result of Tesseract's orientation analysis of the target image. See
 *  `MGOrientation` in MGConstants.h for the possible orientations.
 *  
 *  @note You must have a file called "osd.traineddata" in the "tessdata"
 *        folder to use this method. You can download this file from:
 *        https://code.google.com/p/tesseract-ocr/downloads/list
 */
@property (nonatomic, readonly) MGOrientation orientation;

/**
 *  The result of Tesseract's writing direction analysis of the target image. 
 *  See `MGWritingDirection` in MGConstants.h for the possible writing 
 *  directions.
 *
 *  @note You must have a file called "osd.traineddata" in the "tessdata"
 *        folder to use this method. You can download this file from:
 *        https://code.google.com/p/tesseract-ocr/downloads/list
 */
@property (nonatomic, readonly) MGWritingDirection writingDirection;

/**
 *  The result of Tesseract's textline order analysis of the target image.
 *  See `MGTextlineOrder` in MGConstants.h for the possible textline orderings.
 *
 *  @note You must have a file called "osd.traineddata" in the "tessdata"
 *        folder to use this method. You can download this file from:
 *        https://code.google.com/p/tesseract-ocr/downloads/list
 */
@property (nonatomic, readonly) MGTextlineOrder textlineOrder;

/**
 *  The result of Tesseract's deskew angle analysis of the target image.
 *  This quantity is the number of radians required to rotate the image
 *  counter-clockwise for the text to be level. The deskew angle will be 
 *  between -Pi/4 and Pi/4.
 *
 *  @note You must have a file called "osd.traineddata" in the "tessdata"
 *        folder to use this method. You can download this file from:
 *        https://code.google.com/p/tesseract-ocr/downloads/list
 */
@property (nonatomic, readonly) CGFloat deskewAngle;

/**
 *  An array of arrays, where each subarray contains `MGRecognizedBlock`'s
 *  representing the choices Tesseract considered for each symbol in the target
 *  image. See MGRecognizedBlock.h for more information about the available
 *  fields for this data structure.
 *
 *  @note It has been observed that this method only works when using the 
 *        `MGOCREngineModeTesseractOnly` mode for `engineMode`. It returns nil,
 *        if the engine is not properly configured.
 */
@property (nonatomic, readonly) NSArray *characterChoices;

/**
 *  Retrieve Tesseract's recognition result based on a provided resolution.
 *  For example, the pageIteratorLevel == MGPageIteratorLevelSymbol returns
 *  an array of `MGRecognizedBlock`'s representing the characters recognized
 *  in the target image, including the bounding boxes for each character.
 *
 *  @param pageIteratorLevel A `MGPageIteratorLevel` representing the resolution
 *                           of interest. See MGConstants.h for the available 
 *                           resolution options.
 *
 *  @return An array of `MGRecognizedBlock`'s, each containing a confidence
 *          value and a bounding box for the text it represents. See 
 *          MGRecognizedBlock.h for more information about the available fields 
 *          for this data structure.
 *
 *  @note The method returns nil, if the engine is not properly configured.
 */
- (NSArray *)recognizedBlocksByIteratorLevel:(MGPageIteratorLevel)pageIteratorLevel;

#pragma mark - Debug methods

/**
 *  The result of Tesseract's internal thresholding on the target image or nil,
 *  if engine is not properly configured
 */
@property (nonatomic, readonly) UIImage *thresholdedImage;

/**
 *  Create a copy of the target image with boxes (and optionally labels) drawn 
 *  for each provided recognition block.
 *
 *  @param blocks      An array of `MGRecognizedBlock`'s to draw on the image.
 *  @param drawText    Whether or not to draw text on the image.
 *  @param thresholded Whether or not to use Tesseract's thresholded image.
 *
 *  @return The resulting image.
 */
- (UIImage *)imageWithBlocks:(NSArray *)blocks
                    drawText:(BOOL)drawText
                 thresholded:(BOOL)thresholded;

/**
 *  An optional delegate for Tesseract's recognition.
 */
@property (nonatomic, weak) id<MGTesseractDelegate> delegate;

/**
 *  The default initializer.
 *  @return A MGTesseract instance initialized with neither language,
 *          nor any other settings specified. You can set the language later, 
 *          using language property.
 */
- (instancetype)init;

/**
 *  Initialize Tesseract with the provided language.
 *
 *  @param language The language to use in recognition. See `language`.
 *
 *  @return The initialized Tesseract object. 
 *
 *  @note   You should check that the `language` property matches the languages
 *          you have specified. Also you may ensure that Tesseract is properly
 *          initialized by checking `isEngineConfigured` property.
 */
- (instancetype)initWithLanguage:(NSString*)language;

/**
 *  Initialize Tesseract with the provided language and engine mode.
 *
 *  @param language   The language to use in recognition. See `language`.
 *  @param engineMode The engine mode to use in recognition. See `engineMode`.
 *
 *  @return The initialized Tesseract object. 
 *
 *  @note   You should check that the `language` property matches the languages
 *          you have specified. Also you may ensure that Tesseract is properly
 *          initialized by checking `isEngineConfigured` property.
 */
- (instancetype)initWithLanguage:(NSString*)language
                      engineMode:(MGOCREngineMode)engineMode;

/**
 *  Initialize Tesseract with the provided language and engine mode.
 *
 *  @param language             The language to use in recognition. See 
 *                              `language`.
 *  @param configDictionary     A dictionary of config variables to set.
 *  @param configFileNames      An array of file names containing key-value 
 *                              config pairs. Config settings can be set at
 *                              initialization or run-time.  Furthermore, they 
 *                              could be specified at the same time, in which 
 *                              case Tesseract will get variables from every
 *                              config file as well as the dictionary.
 *                              The config files must exist in one of two 
 *                              possible folders:  tessdata/tessconfigs or 
 *                              tessdata/configs.
 *  @param cachesRelatedPath    If the cachesRelatedDataPath is specified, the 
 *                              whole contents of the tessdata folder in the
 *                              application bundle will be copied to 
 *                              Library/Caches/cachesRelatedDataPath/tessdata
 *                              and Tesseract will be set to use that path.
 *  @param engineMode           The engine mode to use in recognition. See 
 *                              `engineMode`.
 *
 *  @return The initialized Tesseract object.
 *
 *  @note   You should check that the `language` property matches the languages
 *          you have specified. Also you may ensure that Tesseract is properly
 *          initialized by checking `isEngineConfigured` property.
 */

- (instancetype)initWithLanguage:(NSString *)language
                configDictionary:(NSDictionary *)configDictionary
                 configFileNames:(NSArray *)configFileNames
           cachesRelatedDataPath:(NSString *)cachesRelatedDataPath
                      engineMode:(MGOCREngineMode)engineMode;

/**
 *  Initialize Tesseract with the provided language and engine mode.
 *
 *  @param language                 The language to use in recognition. See
 *                                  `language`.
 *  @param configDictionary         A dictionary of config variables to set.
 *  @param configFileNames          An array of file names containing key-value
 *                                  config pairs. Config settings can be set at
 *                                  initialization or run-time.  Furthermore, they
 *                                  could be specified at the same time, in which
 *                                  case Tesseract will get variables from every
 *                                  config file as well as the dictionary.
 *                                  The config files must exist in one of two
 *                                  possible folders:  tessdata/tessconfigs or
 *                                  tessdata/configs.
 *  @param absoluteDataPath         If specified, the whole contents of the 
 *                                  tessdata folder in the application bundle
 *                                  (if present) will be copied to
 *                                  <absoluteDataPath>/tessdata and Tesseract will
 *                                  be initialized to use this path as the path
 *                                  prefix for the tessdata folder.
 *                                  Consequently, you must have a folder named
 *                                  "tessdata" in this path for Tesseract to
 *                                  initialize properly if there is no tessdata
 *                                  folder in the application bundle. If nil, the
 *                                  application bundle will be used instead as the
 *                                  path prefix for the tessdata folder.
 *  @param engineMode               The engine mode to use in recognition. See
 *                                  `engineMode`.
 *
 *
 *  @return The initialized Tesseract object.
 *
 *  @note   You should check that the `language` property matches the languages
 *          you have specified. Also you may ensure that Tesseract is properly
 *          initialized by checking `isEngineConfigured` property.
 */
- (instancetype)initWithLanguage:(NSString *)language
                configDictionary:(NSDictionary *)configDictionary
                 configFileNames:(NSArray *)configFileNames
                absoluteDataPath:(NSString *)absoluteDataPath
                      engineMode:(MGOCREngineMode)engineMode NS_DESIGNATED_INITIALIZER;

/**
 *  Set a Tesseract variable. See MGTesseractParameters.h for the available
 *  options.
 *
 *  @param value The value to use for the option.
 *  @param key   The option to set.
 */
- (void)setVariableValue:(NSString *)value forKey:(NSString *)key;

/**
 *  Returns a Tesseract variable for the given key. See MGTesseractParameters.h 
 *  for the available options.
 *
 *  @param key  The option to get.
 *
 *  @return     Returns the variable value for the given key, if it's been set. 
 *              nil otherwise. Also returns nil if the engine is not properly 
 *              configured. Refer to `isEngineConfigured` property.
 */
- (NSString*)variableValueForKey:(NSString *)key;

/**
 *  Set Tesseract variables using a dictionary. See MGTesseractParameters.h for 
 *  the available options. Only runtime variables could be set. To set up 
 *  initial time variables use 
 *  initWithLanguage:configDictionary:configFileNames:cachesRelatedDataPath:engineMode:
 *
 *  @param dictionary The dictionary of key/value pairs to set for Tesseract.
 */
- (void)setVariablesFromDictionary:(NSDictionary *)dictionary;

/**
 *  Execute recognition on the target image.
 *
 *  @return Whether or not the recognition completed successfully.
 */
- (BOOL)recognize;

@end
