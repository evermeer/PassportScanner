//
//  MGTesseractParameters.h
//  Tesseract OCR iOS
//  This code is auto-generated from Tesseract headers.
//
//
//  Created by Mister Grizzly on 2018.
//  Copyright (c) 2018 Mister Grizzly - www.mistergrizzly.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef Tesseract_OCR_iOS_MGTesseractParameters_h
#define Tesseract_OCR_iOS_MGTesseractParameters_h

///Expect spaces bigger than this
///@param Type double
///@param Default 0.33
extern NSString *const kMGParamTospTableXhtSpRatio;

///Generate training data from boxed chars
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditTrainFromBoxes;

///* blob height for initial linesize
///@param Type double
///@param Default 1.25
extern NSString *const kMGParamTextordMinLinesize;

///Fract of xheight for wide
///@param Type double
///@param Default 0.52
extern NSString *const kMGParamTospWideFraction;

///Use spline baseline
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamTextordFixXheightBug;

///Good blob limit
///@param Type double
///@param Default -2.25
extern NSString *const kMGParamTesseditCertaintyThreshold;

///Penalty increment
///@param Type double
///@param Default 0.01
extern NSString *const kMGParamLanguageModelPenaltyIncrement;

///Learn both character fragments (as is done in the special low exposure mode) as well as unfragmented characters.
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamApplyboxLearnCharsAndCharFragsMode;

///Generate more boxes from boxed chars
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditMakeBoxesFromBoxes;

///How wide fuzzies need context
///@param Type double
///@param Default 0.75
extern NSString *const kMGParamTospPassWideFuzzSpToContext;

///Use pre-adapted classifier templates
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamClassifyUsePreAdaptedTemplates;

///Split overlap adjustment
///@param Type double
///@param Default 0.9
extern NSString *const kMGParamChopOverlapKnob;

///Extend permuter check
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamRejAlphasInNumberPerm;

///Baseline Normalized Matching
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamTessBnMatching;

///Dont bother with word plausibility
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditUnrejAnyWd;

///Dump word pass/fail chk
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamDebugAcceptableWds;

///Debug data
///@param Type INT
///@param Default 0
extern NSString *const kMGParamTospDebugLevel;

///Use information from fragments to guide chopping process
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamFragmentsGuideChopper;

///Factor to expand rows by in expand_rows
///@param Type double
///@param Default 1.0
extern NSString *const kMGParamTextordExpansionFactor;

///Write repetition char code
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditWriteRepCodes;

///Print cube debug info.
///@param Type INT
///@param Default 1
extern NSString *const kMGParamCubeDebugLevel;

///Load unambiguous word dawg.
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLoadUnambigDawg;

///Take segmentation and labeling from box file
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditResegmentFromBoxes;

///Min # of permanent classes
///@param Type INT
///@param Default 1
extern NSString *const kMGParamMatcherPermanentClassesMin;

///POTENTIAL crunch rating lt this
///@param Type double
///@param Default 60
extern NSString *const kMGParamCrunchDelRating;

///Default flip
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospFlipFuzzKnToSp;

///Score multiplier for word matches which have good case and are frequent in the given language (lower is better).
///@param Type double
///@param Default 1.0
extern NSString *const kMGParamSegmentPenaltyDictFrequentWord;

///Factor to bring log-probs into the same range as ratings when multiplied by outline length
///@param Type double
///@param Default 16.0
extern NSString *const kMGParamLanguageModelNgramRatingFactor;

///rep gap multiplier for space
///@param Type double
///@param Default 1.6
extern NSString *const kMGParamTospRepSpace;

///or should we use mean
///@param Type INT
///@param Default 3
extern NSString *const kMGParamTospEnoughSpaceSamplesForMedian;

///Min Number of Points on Outline
///@param Type INT
///@param Default 6
extern NSString *const kMGParamChopMinOutlinePoints;

///Max large speckle size
///@param Type double
///@param Default 0.30
extern NSString *const kMGParamSpeckleLargeMaxSize;

///Which OCR engine(s) to run (Tesseract, Cube, both). Defaults to loading and running only Tesseract (no Cube, no combiner). (Values from OcrEngineMode enum in tesseractclass.h)
///@param Type INT
///@param Default tesseract::OEM_TESSERACT_ONLY
extern NSString *const kMGParamTesseditOcrEngineMode;

///Output text with boxes
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditCreateBoxfile;

///How many times worse certainty does a superscript position glyph need to be for us to try classifying it as a char with a different baseline?
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamSuperscriptWorseCertainty;

///Maximum size of viterbi list.
///@param Type INT
///@param Default 10
extern NSString *const kMGParamMaxViterbiListSize;

///Good split limit
///@param Type double
///@param Default 50.0
extern NSString *const kMGParamChopGoodSplit;

///Individual rejection control
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamRejUseTessBlanks;

///Blacklist of chars not to recognize
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamTesseditCharBlacklist;

///Min blobs before gradient counted
///@param Type INT
///@param Default 4
extern NSString *const kMGParamTextordMinBlobsInRow;

///coord of test pt
///@param Type INT
///@param Default -MAX_INT32
extern NSString *const kMGParamTextordTestY;

///coord of test pt
///@param Type INT
///@param Default -MAX_INT32
extern NSString *const kMGParamTextordTestX;

///A list of user-provided patterns.
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamUserPatternsSuffix;

///Use within xht gap for wd breaks
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospUseXhtGaps;

///Conversion of word/line box file to char box file
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditResegmentFromLineBoxes;

///Mark v.bad words for tilde crunch
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamUnlvTildeCrunching;

///SegSearch debug level
///@param Type INT
///@param Default 0
extern NSString *const kMGParamSegsearchDebugLevel;

///Load dawg with number patterns.
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLoadNumberDawg;

///Worst certainty for words that can be inserted into the document dictionary
///@param Type double
///@param Default -2.25
extern NSString *const kMGParamDocDictCertaintyThreshold;

///Min blobs in each spline segment
///@param Type INT
///@param Default 8
extern NSString *const kMGParamTextordSplineMinblobs;

///POTENTIAL crunch rating lt this
///@param Type double
///@param Default 40
extern NSString *const kMGParamCrunchPotPoorRate;

///Test xheight algorithms
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordDebugXheights;

///Suspect marker level
///@param Type INT
///@param Default 99
extern NSString *const kMGParamSuspectLevel;

///crunch garbage rating lt this
///@param Type double
///@param Default 60
extern NSString *const kMGParamCrunchPoorGarbageRate;

///Display unsorted blobs
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTextordShowBlobs;

///Accepted variation
///@param Type double
///@param Default 0.1
extern NSString *const kMGParamTextordXheightErrorMargin;

///Save adapted templates to a file
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamClassifySaveAdaptedTemplates;

///Allow NN to unrej
///@param Type STRING
///@param Default "-?*\075"
extern NSString *const kMGParamOkRepeatedChNonAlphanumWds;

///Maximum number of prunable (those for which PrunablePath() is true) entries in each viterbi list recorded in BLOB_CHOICEs
///@param Type INT
///@param Default 10
extern NSString *const kMGParamLanguageModelViterbiListMaxNumPrunable;

///Dont crunch words with long lower case strings
///@param Type INT
///@param Default 4
extern NSString *const kMGParamCrunchLeaveUcStrings;

///Strength of the character ngram model relative to the character classifier
///@param Type double
///@param Default 0.03
extern NSString *const kMGParamLanguageModelNgramScaleFactor;

///xh fract width error for norm blobs
///@param Type double
///@param Default 0.4
extern NSString *const kMGParamTextordNoiseSxfract;

///Max number of seams in seam_pile
///@param Type INT
///@param Default 150
extern NSString *const kMGParamChopSeamPileSize;

///Perform training for ambiguities
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditAmbigsTraining;

///Block stats to use fixed pitch rows?
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospOnlyUsePropRows;

///Print paragraph debug info.
///@param Type INT
///@param Default 0
extern NSString *const kMGParamParagraphDebugLevel;

///good_quality_doc lte outline error limit
///@param Type double
///@param Default 1.0
extern NSString *const kMGParamQualityOutlinePc;

///Debug level for TessdataManager functions.
///@param Type INT
///@param Default 0
extern NSString *const kMGParamTessdataManagerDebugLevel;

///Print blamer debug messages
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamWordrecDebugBlamer;

///Rejection algorithm
///@param Type INT
///@param Default 0
extern NSString *const kMGParamTesseditRejectMode;

///crunch rating lt this
///@param Type double
///@param Default 80.0
extern NSString *const kMGParamCrunchTerribleRating;

///Certainty threshold for non-dict words
///@param Type double
///@param Default -2.50
extern NSString *const kMGParamStopperNondictCertaintyBase;

///Default score multiplier for word matches, which may have case issues (lower is better).
///@param Type double
///@param Default 1.3125
extern NSString *const kMGParamSegmentPenaltyDictCaseBad;

///Apply row rejection to good docs
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditRowRejGoodDocs;

///Display blob bounds after pre-ass
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordShowFinalBlobs;

///Average classifier score of a non-matching unichar
///@param Type double
///@param Default -40.0
extern NSString *const kMGParamLanguageModelNgramNonmatchScore;

///Language model debug level
///@param Type INT
///@param Default 0
extern NSString *const kMGParamLanguageModelDebugLevel;

///good_quality_doc gte good char limit
///@param Type double
///@param Default 1.1
extern NSString *const kMGParamQualityRowrejPc;

///Maximum number of pain point classifications per word.
///@param Type INT
///@param Default 10
extern NSString *const kMGParamSegsearchMaxFutileClassifications;

///Call Tess to learn blobs
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditTrainingTess;

///Del if word gt xht x this below bl
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamCrunchDelLowWord;

///Penalty for inconsistent script
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamLanguageModelPenaltyScript;

///Exclude fragments that do not match any whole character with at least this certainty
///@param Type double
///@param Default -3.0
extern NSString *const kMGParamClassifyCharacterFragmentsGarbageCertaintyThreshold;

///Class Pruner CutoffStrength:
///@param Type INT
///@param Default 7
extern NSString *const kMGParamClassifyCpCutoffStrength;

///Only rej partially rejected words in block rejection
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditPreserveBlkRejPerfectWds;

///Aspect ratio dot/hyphen test
///@param Type double
///@param Default 1.8
extern NSString *const kMGParamTesseditUpperFlipHyphen;

///OK split limit
///@param Type double
///@param Default 100.0
extern NSString *const kMGParamChopOkSplit;

///For smooth factor
///@param Type INT
///@param Default 4
extern NSString *const kMGParamTextordSkewsmoothOffset;

///Score penalty (0.1 = 10%) added if an xheight is inconsistent.
///@param Type double
///@param Default 0.25
extern NSString *const kMGParamXheightPenaltyInconsistent;

///Chop debug
///@param Type INT
///@param Default 0
extern NSString *const kMGParamChopDebug;

///Reject noise-like words
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTextordNoiseRejwords;

///Debug character fragments
///@param Type INT
///@param Default 0
extern NSString *const kMGParamFragmentsDebug;

///Dot to norm ratio for deletion
///@param Type double
///@param Default 6.0
extern NSString *const kMGParamTextordNoiseRowratio;

///X / Y  length weight
///@param Type INT
///@param Default 3
extern NSString *const kMGParamChopXYWeight;

///Max allowed deviation of blob top outside of font data
///@param Type INT
///@param Default 8
extern NSString *const kMGParamXHtAcceptanceTolerance;

///Maximum number of different character choices to consider during permutation. This limit is especially useful when user patterns are specified, since overly generic patterns can result in dawg search exploring an overly large number of options.
///@param Type INT
///@param Default 10000
extern NSString *const kMGParamMaxPermuterAttempts;

///Use sigmoidal score for certainty
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamLanguageModelUseSigmoidalCertainty;

///Force straight baselines
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordStraightBaselines;

///Reestimate debug
///@param Type INT
///@param Default 0
extern NSString *const kMGParamDebugXHtLevel;

///Dont pot crunch sensible strings
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamCrunchLeaveAcceptStrings;

///Generate and print debug information for adaption
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditAdaptionDebug;

///Output data to debug file
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDebugQualityMetrics;

///Only stat OBVIOUS spaces
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospBlockUseCertSpaces;

///Only reject tess failures
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditMinimalRejection;

///Del if word ht lt xht x this
///@param Type double
///@param Default 0.7
extern NSString *const kMGParamCrunchDelMinHt;

///gap ratio to flip sp->kern
///@param Type double
///@param Default 0.83
extern NSString *const kMGParamTospGapFactor;

///Prevent multiple baselines
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamTextordFixMakerowBug;

///Only run OCR for words that had truth recorded in BlamerBundle
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamWordrecSkipNoTruthWords;

///Height fraction to discard outlines as speckle noise
///@param Type double
///@param Default 1.0/64
extern NSString *const kMGParamTextordNoiseHfract;

///xh fract error for norm blobs
///@param Type double
///@param Default 0.2
extern NSString *const kMGParamTextordNoiseSyfract;

///Penalty for inconsistent spacing
///@param Type double
///@param Default 0.05
extern NSString *const kMGParamLanguageModelPenaltySpacing;

///Debug level for sub & superscript fixer
///@param Type INT
///@param Default 0
extern NSString *const kMGParamSuperscriptDebug;

///Don't output block information
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamWordrecNoBlock;

///Lag for skew on row accumulation
///@param Type double
///@param Default 0.02
extern NSString *const kMGParamTextordSkewLag;

///Vertical creep
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamChopVerticalCreep;

///Min suspect level for rejecting spaces
///@param Type INT
///@param Default 100
extern NSString *const kMGParamSuspectSpaceLevel;

///Min char x-norm scale ...
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamClassifyMinNormScaleX;

///Write .pdf output file
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditCreatePdf;

///Penalty for inconsistent font
///@param Type double
///@param Default 0.00
extern NSString *const kMGParamLanguageModelPenaltyFont;

///Page number to apply boxes from
///@param Type INT
///@param Default 0
extern NSString *const kMGParamApplyboxPage;

///Classify debug level
///@param Type INT
///@param Default 0
extern NSString *const kMGParamClassifyDebugLevel;

///Use only the first UTF8 step of the given string when computing log probabilities.
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamUseOnlyFirstUft8Step;

///rej good doc wd if more than this fraction rejected
///@param Type double
///@param Default 1.1
extern NSString *const kMGParamTesseditGoodDocStillRowrejWd;

///Use DOC dawg in 11l conf. detector
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamRejTrustDocDawg;

///Only stat OBVIOUS spaces
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospRowUseCertSpaces1;

///No.samples reqd to reestimate for row
///@param Type INT
///@param Default 10
extern NSString *const kMGParamTospRedoKernLimit;

///Del if word ht gt xht x this
///@param Type double
///@param Default 3.0
extern NSString *const kMGParamCrunchDelMaxHt;

///Veto ratio between classifier ratings
///@param Type double
///@param Default 1.5
extern NSString *const kMGParamClassifyMaxRatingRatio;

///Min cap/xheight
///@param Type double
///@param Default 1.25
extern NSString *const kMGParamTextordAscxRatioMin;

///Output char for unidentified blobs
///@param Type STRING
///@param Default "|"
extern NSString *const kMGParamUnrecognisedChar;

///Del if word width lt xht x this
///@param Type double
///@param Default 3.0
extern NSString *const kMGParamCrunchDelMinWidth;

///Min difference of kn & sp in table
///@param Type double
///@param Default 2.25
extern NSString *const kMGParamTospTableKnSpRatio;

///Min pile height to make ascheight
///@param Type double
///@param Default 0.08
extern NSString *const kMGParamTextordAscheightModeFraction;

///A superscript scaled down more than this is unbelievably small.  For example, 0.3 means we expect the font size to be no smaller than 30% of the text line font size.
///@param Type double
///@param Default 0.4
extern NSString *const kMGParamSuperscriptScaledownRatio;

///wide if w/h less than this
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamTospWideAspectRatio;

///Dont trust spaces less than this time kn
///@param Type double
///@param Default 1.5
extern NSString *const kMGParamTospMinSaneKnSp;

///Fract of xheight for fuzz sp
///@param Type double
///@param Default 0.6
extern NSString *const kMGParamTospFuzzySpaceFactor;

///Scale factor for features not used
///@param Type double
///@param Default 0.00390625
extern NSString *const kMGParamTesseditClassMissScale;

///POTENTIAL crunch cert lt this
///@param Type double
///@param Default -10.0
extern NSString *const kMGParamCrunchDelCert;

///Lengths of unichars in word_to_debug
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamWordToDebugLengths;

///Min pile height to make descheight
///@param Type double
///@param Default 0.08
extern NSString *const kMGParamTextordDescheightModeFraction;

///Capture the image from the IPE
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditWriteImages;

///Dont touch bad rating limit
///@param Type double
///@param Default 999.9
extern NSString *const kMGParamSuspectRatingPerCh;

///Run in parallel where possible
///@param Type INT
///@param Default 0
extern NSString *const kMGParamTesseditParallelize;

///Certainty to add for each dict char above small word size.
///@param Type double
///@param Default -0.50
extern NSString *const kMGParamStopperCertaintyPerChar;

///Test for point
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTestPt;

///Words are delimited by space
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLanguageModelNgramSpaceDelimitedLanguage;

///For adj length in rating per ch
///@param Type INT
///@param Default 10
extern NSString *const kMGParamCrunchRatingMax;

///Penalty for inconsistent case
///@param Type double
///@param Default 0.1
extern NSString *const kMGParamLanguageModelPenaltyCase;

///Fract of kerns reqd for isolated row stats
///@param Type double
///@param Default 0.65
extern NSString *const kMGParamTospEnoughSmallGaps;

///Accept good rating limit
///@param Type double
///@param Default -999.9
extern NSString *const kMGParamSuspectAcceptRating;

///Veto difference between classifier certainties
///@param Type double
///@param Default 5.5
extern NSString *const kMGParamClassifyMaxCertaintyMargin;

///Class Pruner Multiplier 0-255:
///@param Type INT
///@param Default 15
extern NSString *const kMGParamClassifyClassPrunerMultiplier;

///Individual rejection control
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamRejUseGoodPerm;

///Dont adapt to i/I at beginning of word
///@param Type INT
///@param Default 0
extern NSString *const kMGParamIl1AdaptionTest;

///Min change in xht before actually trying it
///@param Type INT
///@param Default 8
extern NSString *const kMGParamXHtMinChange;

///POTENTIAL crunch garbage
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamCrunchPotGarbage;

///Max words to keep in list
///@param Type INT
///@param Default 10
extern NSString *const kMGParamTesseditTruncateWordchoiceLog;

///Enable adaptive classifier
///@param Type BOOL
///@param Default 1
extern NSString *const kMGParamClassifyEnableAdaptiveMatcher;

///Write .html hOCR output file
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditCreateHocr;

///Certainty scaling factor
///@param Type double
///@param Default 20.0
extern NSString *const kMGParamCertaintyScale;

///Size of dict word to be treated as non-dict word
///@param Type INT
///@param Default 2
extern NSString *const kMGParamStopperSmallwordSize;

///Max number of broken pieces to associate
///@param Type INT
///@param Default 4
extern NSString *const kMGParamWordrecMaxJoinChunks;

///Dot to norm ratio for deletion
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamTextordNoiseNormratio;

///Split length adjustment
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamChopSplitDistKnob;

///Debug level for hyphenated words.
///@param Type INT
///@param Default 0
extern NSString *const kMGParamHyphenDebugLevel;

///Write .unlv output file
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditWriteUnlv;

///good_quality_doc gte good blobs limit
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamQualityBlobPc;

///super norm blobs to save row
///@param Type INT
///@param Default 1
extern NSString *const kMGParamTextordNoiseSncount;

///Fract of xheight for fuzz sp
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamTospFuzzySpaceFactor1;

///Fract of xheight for fuzz sp
///@param Type double
///@param Default 0.72
extern NSString *const kMGParamTospFuzzySpaceFactor2;

///Run interactively?
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamInteractiveDisplayMode;

///Fraction of size for maxima
///@param Type INT
///@param Default 10
extern NSString *const kMGParamTextordNoiseSizefraction;

///Write block separators in output
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditWriteBlockSeparators;

///Adaptation decision algorithm for tess
///@param Type INT
///@param Default 3
extern NSString *const kMGParamTesseditTestAdaptionMode;

///Allow feature extractors to see the original outline
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamPolyAllowDetailedFx;

///Space stats use prechopping?
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospUsePreChopping;

///narrow if w/h less than this
///@param Type double
///@param Default 0.48
extern NSString *const kMGParamTospNarrowAspectRatio;

///Display page correlated rows
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordShowParallelRows;

///Percentile for small blobs
///@param Type double
///@param Default 20
extern NSString *const kMGParamTextordBlobSizeSmallile;

///As it says
///@param Type INT
///@param Default 0
extern NSString *const kMGParamCrunchDebug;

///Enable match debugger
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamClassifyEnableAdaptiveDebugger;

///Crunch words with long repetitions
///@param Type INT
///@param Default 3
extern NSString *const kMGParamCrunchLongRepetitions;

///Penalty for inconsistent character type
///@param Type double
///@param Default 0.3
extern NSString *const kMGParamLanguageModelPenaltyChartype;

///Perfect Match (0-1)
///@param Type double
///@param Default 0.02
extern NSString *const kMGParamMatcherPerfectThreshold;

///Penalty for words not in the frequent word dictionary
///@param Type double
///@param Default 0.1
extern NSString *const kMGParamLanguageModelPenaltyNonFreqDictWord;

///Vigorously remove noise
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordHeavyNr;

///how far between kern and space?
///@param Type double
///@param Default 0
extern NSString *const kMGParamTospThresholdBias2;

///how far between kern and space?
///@param Type double
///@param Default 0
extern NSString *const kMGParamTospThresholdBias1;

///Force parallel baselines
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamTextordParallelBaselines;

///%rej allowed before rej whole row
///@param Type double
///@param Default 40.00
extern NSString *const kMGParamTesseditRejectRowPercent;

///Threshold for good features during adaptive 0-255
///@param Type INT
///@param Default 230
extern NSString *const kMGParamClassifyAdaptFeatureThreshold;

///Width change adjustment
///@param Type double
///@param Default 5.0
extern NSString *const kMGParamChopWidthChangeKnob;

///Dont reject ANYTHING AT ALL
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditZeroKelvinRejection;

///Pixel size of noise
///@param Type INT
///@param Default 7
extern NSString *const kMGParamTextordMaxNoiseSize;

///Dont autoflip kn to sp when large separation
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamTospFlipCaution;

///xcoord
///@param Type double
///@param Default 99999.99
extern NSString *const kMGParamTestPtX;

///Reduce rejection on good docs
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditGoodQualityUnrej;

///Learning Debug Level:
///@param Type INT
///@param Default 0
extern NSString *const kMGParamClassifyLearningDebugLevel;

///xht multiplier
///@param Type double
///@param Default -1
extern NSString *const kMGParamTospIgnoreBigGaps;

///Load system word dawg.
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLoadSystemDawg;

///Only stat OBVIOUS spaces
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospNarrowBlobsNotCert;

///Turn on/off the use of character ngram model
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamLanguageModelNgramOn;

///Try to set the blame for errors
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamWordrecRunBlamer;

///Fuzzy if less than this
///@param Type double
///@param Default 3.0
extern NSString *const kMGParamTospTableFuzzyKnSpRatio;

///Don't remove noise blobs
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTextordNoRejects;

///Rej blbs near image edge limit
///@param Type INT
///@param Default 2
extern NSString *const kMGParamTesseditImageBorder;

///Pass ANY flip to context?
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospAllFlipsFuzzy;

///Contextual fixspace debug
///@param Type INT
///@param Default 0
extern NSString *const kMGParamDebugFixSpaceLevel;

///Use dictword test
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamRej1IlUseDictWord;

///Debug row garbage detector
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordNoiseDebug;

///Don't use any alphabetic-specific tricks. Set to true in the traineddata config file for scripts that are cursive or inherently fixed-pitch
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamSegmentNonalphabeticScript;

///Space stats use prechopping?
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospOldToMethod;

///Print timing stats
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditTimingDebug;

///Prioritize blob division over chopping
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamPrioritizeDivision;

///Add words to the document dictionary
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditEnableDocDict;

///POTENTIAL crunch cert lt this
///@param Type double
///@param Default -8.0
extern NSString *const kMGParamCrunchPotPoorCert;

///Score multiplier for glyph fragment segmentations which do not match a dictionary word (lower is better).
///@param Type double
///@param Default 1.25
extern NSString *const kMGParamSegmentPenaltyDictNonword;

///crunch garbage cert lt this
///@param Type double
///@param Default -9.0
extern NSString *const kMGParamCrunchPoorGarbageCert;

///Fraction of neighbourhood
///@param Type double
///@param Default 0.4
extern NSString *const kMGParamTextordOccupancyThreshold;

///Script has no xheight, so use a single mode for horizontal text
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTextordSingleHeightMode;

///How many potential indicators needed
///@param Type INT
///@param Default 1
extern NSString *const kMGParamCrunchPotIndicators;

///Min size of baseline shift
///@param Type double
///@param Default 9.99
extern NSString *const kMGParamTextordBlshiftXfraction;

///Constrain relative values of inter and intra-word gaps for old_to_method.
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospOldToConstrainSpKn;

///Rating scaling factor
///@param Type double
///@param Default 1.5
extern NSString *const kMGParamRatingScale;

///Fraction of line spacing for quad
///@param Type double
///@param Default 0.02
extern NSString *const kMGParamTextordSplineShiftFraction;

///Max desc/xheight
///@param Type double
///@param Default 0.6
extern NSString *const kMGParamTextordDescxRatioMax;

///Force all rep chars the same
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditConsistentReps;

///Dont let sp minus kn get too small
///@param Type double
///@param Default 0.2
extern NSString *const kMGParamTospSillyKnSpGap;

///Penalty for non-dictionary words
///@param Type double
///@param Default 0.15
extern NSString *const kMGParamLanguageModelPenaltyNonDictWord;

///Max width before chopping
///@param Type double
///@param Default 1.5
extern NSString *const kMGParamTextordChopWidth;

///Fraction of linespace for good overlap
///@param Type double
///@param Default 0.375
extern NSString *const kMGParamTextordOverlapX;

///Make output have exactly one word per WERD
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditWordForWord;

///Segmentation adjustment debug
///@param Type INT
///@param Default 0
extern NSString *const kMGParamSegmentAdjustDebug;

///Min pile height to make xheight
///@param Type double
///@param Default 0.4
extern NSString *const kMGParamTextordXheightModeFraction;

///In multilingual mode use params model of the primary language
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditUsePrimaryParamsModel;

///How many non-noise blbs either side?
///@param Type INT
///@param Default 1
extern NSString *const kMGParamFixspNonNoiseLimit;

///Minimum bottom of a character measured as a multiple of x-height above the baseline for us to reconsider whether it's a superscript.
///@param Type double
///@param Default 0.3
extern NSString *const kMGParamSuperscriptMinYBottom;

///Maximum size of viterbi lists recorded in BLOB_CHOICEs
///@param Type INT
///@param Default 500
extern NSString *const kMGParamLanguageModelViterbiListMaxSize;

///Max width of blobs to make rows
///@param Type double
///@param Default 8
extern NSString *const kMGParamTextordWidthLimit;

///Fraction of line spacing for outlier
///@param Type double
///@param Default 0.1
extern NSString *const kMGParamTextordSplineOutlierFraction;

///Use within xht gap for wd breaks
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospStatsUseXhtGaps;

///Normalization Method   ...
///@param Type INT
///@param Default character
extern NSString *const kMGParamClassifyNormMethod;

///Min acceptable orientation margin
///@param Type double
///@param Default 7.0
extern NSString *const kMGParamMinOrientationMargin;

///Great Match (0-1)
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamMatcherGreatThreshold;

///Only initialize with the config file. Useful if the instance is not going to be used for OCR but say only for layout analysis.
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditInitConfigOnly;

///Display rows after expanding
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordShowExpandedRows;

///Only rej partially rejected words in row rejection
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditPreserveRowRejPerfectWds;

///New template margin (0-1)
///@param Type double
///@param Default 0.1
extern NSString *const kMGParamMatcherRatingMargin;

///Do not include character fragments in the results of the classifier
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamDisableCharacterFragments;

///Maximum top of a character measured as a multiple of x-height above the baseline for us to reconsider whether it's a subscript.
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamSubscriptMaxYTop;

///Merge the fragments in the ratings matrix and delete them after merging
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamMergeFragmentsInMatrix;

///unrej potential with no chekcs
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamBlandUnrej;

///Del if word gt xht x this above bl
///@param Type double
///@param Default 1.5
extern NSString *const kMGParamCrunchDelHighWord;

///fraction of linesize for min xheight
///@param Type double
///@param Default 0.25
extern NSString *const kMGParamTextordMinxh;

///Factor for defining space threshold in terms of space and kern sizes
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamTospOldSpKnThFactor;

///To avoid overly small denominators use this as the floor of the probability returned by the ngram model
///@param Type double
///@param Default 0.000001
extern NSString *const kMGParamLanguageModelNgramSmallProb;

///Non standard number of outlines
///@param Type STRING
///@param Default "%| "
extern NSString *const kMGParamOutlinesOdd;

///Log matcher activity
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditMatcherLog;

///Stopper debug level
///@param Type INT
///@param Default 0
extern NSString *const kMGParamStopperDebugLevel;

///Reject all bad quality wds
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditRejectBadQualWds;

///, Punct. chs expected WITHIN numbers
///@param Type STRING
///@param Default ".
extern NSString *const kMGParamNumericPunctuation;

///Split sharpness adjustment
///@param Type double
///@param Default 0.06
extern NSString *const kMGParamChopSharpnessKnob;

///Il1 conflict set
///@param Type STRING
///@param Default "Il1[]"
extern NSString *const kMGParamConflictSetIL1;

///Integer Matcher Multiplier  0-255:
///@param Type INT
///@param Default 10
extern NSString *const kMGParamClassifyIntegerMatcherMultiplier;

///Dont Suspect dict wds longer than this
///@param Type INT
///@param Default 2
extern NSString *const kMGParamSuspectShortWords;

///Assume the input is numbers [0-9].
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamClassifyBlnNumericMode;

///%rej allowed before rej whole block
///@param Type double
///@param Default 45.00
extern NSString *const kMGParamTesseditRejectBlockPercent;

///Non-linear stroke-density normalization
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamClassifyNonlinearNorm;

///Only stat OBVIOUS spaces
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospRowUseCertSpaces;

///Individual rejection control
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamRejUseTessAccepted;

///Maximum angle delta for prototype clustering
///@param Type double
///@param Default 0.015
extern NSString *const kMGParamMatcherClusteringMaxAngleDelta;

///Character Normalization Range ...
///@param Type double
///@param Default 0.2
extern NSString *const kMGParamClassifyCharNormRange;

///Run paragraph detection on the post-text-recognition (more accurate)
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamParagraphTextBased;

///Split center adjustment
///@param Type double
///@param Default 0.15
extern NSString *const kMGParamChopCenterKnob;

///Use test xheight mechanism
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamTextordNewInitialXheight;

///Fraction of x for big t count
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamTextordNoiseSizelimit;

///Penalty to apply when a non-alnum is vertically out of its expected textline position
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamClassifyMisfitJunkPenalty;

///Class str to debug learning
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamClassifyLearnDebugStr;

///Do minimal rejection on pass 1 output
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditMinimalRejPass1;

///Fiddle alpha figures
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamCrunchIncludeNumerals;

///Ile of sizes for xheight guess
///@param Type double
///@param Default 0.90
extern NSString *const kMGParamTextordInitialascIle;

///Filename extension
///@param Type STRING
///@param Default ".tif"
extern NSString *const kMGParamFileType;

///Use word segmentation quality metric
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDontBlkrejGoodWds;

///Test adaption criteria
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditTestAdaption;

///Adaption debug
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditRejectionDebug;

///New fuzzy kn alg
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamTospFuzzyKnFraction;

///Reject spaces?
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditUseRejectSpaces;

///Enable adaptive classifier
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamClassifyEnableLearning;

///Min char y-norm scale ...
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamClassifyMinNormScaleY;

///Matcher Debug Flags
///@param Type INT
///@param Default 0
extern NSString *const kMGParamMatcherDebugFlags;

///Save alternative paths found during chopping and segmentation search
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamSaveAltChoices;

///Use acceptability in okstring
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamCrunchAcceptOk;

///Fraction of bounding box for noise
///@param Type double
///@param Default 0.7
extern NSString *const kMGParamTextordNoiseAreaRatio;

///Whitelist of chars to recognize
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamTesseditCharWhitelist;

///Dont touch sensible strings
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamCrunchLeaveOkStrings;

///xht multiplier
///@param Type double
///@param Default 3.5
extern NSString *const kMGParamTospIgnoreVeryBigGaps;

///good_quality_doc gte good char limit
///@param Type double
///@param Default 0.95
extern NSString *const kMGParamQualityCharPc;

///Enable correction based on the word bigram dictionary.
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditEnableBigramCorrection;

///Penalty to add to worst rating for noise
///@param Type double
///@param Default 10.0
extern NSString *const kMGParamSpeckleRatingPenalty;

///Display boxes
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTextordShowBoxes;

///Score multiplier for word matches that have good case (lower is better).
///@param Type double
///@param Default 1.1
extern NSString *const kMGParamSegmentPenaltyDictCaseOk;

///Page stats
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDebugDocRejection;

///Number of row rejects in whole word rejects which prevents whole row rejection
///@param Type double
///@param Default 70.00
extern NSString *const kMGParamTesseditWholeWdRejRowPercent;

///Class Pruner Threshold 0-255
///@param Type INT
///@param Default 229
extern NSString *const kMGParamClassifyClassPrunerThreshold;

///Try to improve fuzzy spaces
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditFixFuzzySpaces;

///Contextual 0O O0 flips
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditFlip0O;

///Min Outline Area
///@param Type INT
///@param Default 2000
extern NSString *const kMGParamChopMinOutlineArea;

///Dont reject ANYTHING
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditZeroRejection;

///According to dict_word
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditOverridePermuter;

///How to avoid being silly
///@param Type INT
///@param Default 1
extern NSString *const kMGParamTospSanityMethod;

///New fuzzy sp alg
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamTospFuzzySpFraction;

///Deprecated- backward compatability only
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamSaveRawChoices;

///Avg. noise blob length:
///@param Type double
///@param Default 12.0
extern NSString *const kMGParamMatcherAvgNoiseSize;

///alphas in a good word
///@param Type INT
///@param Default 2
extern NSString *const kMGParamQualityMinInitialAlphasReqd;

///Multiplier on kn to limit thresh
///@param Type double
///@param Default 5.0
extern NSString *const kMGParamTospMaxSaneKnThresh;

///Good Match (0-1)
///@param Type double
///@param Default 0.125
extern NSString *const kMGParamMatcherGoodThreshold;

///Word for which stopper debug information should be printed to stdout
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamWordToDebug;

///A list of user-provided words.
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamUserWordsSuffix;

///Use row alone when inadequate cert spaces
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospRecoveryIsolatedRowStats;

///Extend permuter check
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamRejUseSensibleWd;

///Associator Enable
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamWordrecEnableAssoc;

///Top choice only from CP
///@param Type INT
///@param Default FALSE
extern NSString *const kMGParamTesseditSingleMatch;

///Width of (smaller) chopped blobs above which we don't care that a chop is not near the center.
///@param Type INT
///@param Default 90
extern NSString *const kMGParamChopCenteredMaxwidth;

///Load frequent word dawg.
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLoadFreqDawg;

///Ile of gradients for page skew
///@param Type double
///@param Default 0.5
extern NSString *const kMGParamTextordSkewIle;

///Multipler to for the best choice from the ngram model.
///@param Type double
///@param Default 1.24
extern NSString *const kMGParamSegmentPenaltyNgramBestChoice;

///Min desc/xheight
///@param Type double
///@param Default 0.25
extern NSString *const kMGParamTextordDescxRatioMin;

///Score multiplier for poorly cased strings that are not in the dictionary and generally look like garbage (lower is better).
///@param Type double
///@param Default 1.50
extern NSString *const kMGParamSegmentPenaltyGarbage;

///Save Document Words
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamSaveDocWords;

///Split Length
///@param Type INT
///@param Default 10000
extern NSString *const kMGParamChopSplitLength;

///Write all parameters to the given file.
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamTesseditWriteParamsToFile;

///Use old xheight algorithm
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordOldXheight;

///Threshold for good protos during adaptive 0-255
///@param Type INT
///@param Default 230
extern NSString *const kMGParamClassifyAdaptProtoThreshold;

///Debug line finding
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTextordTabfindShowVlines;

///Use two different windows for debugging the matching: One for the protos and one for the features.
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamMatcherDebugSeparateWindows;

///Character Normalized Matching
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamTessCnMatching;

///Size of window for spline segmentation
///@param Type INT
///@param Default 6
extern NSString *const kMGParamTextordSplineMedianwin;

///Default flip
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospFlipFuzzSpToKn;

///Make AcceptableChoice() always return false. Useful when there is a need to explore all segmentations
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamStopperNoAcceptableChoices;

///Worst segmentation state
///@param Type double
///@param Default 1
extern NSString *const kMGParamWordrecWorstState;

///Use old baseline algorithm
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamTextordOldBaselines;

///Transitions for normal blob
///@param Type INT
///@param Default 16
extern NSString *const kMGParamTextordNoiseTranslimit;

///Output font info per char
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDebugFonts;

///Reject noise-like rows
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTextordNoiseRejrows;

///Use CJK fixed pitch model
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordUseCjkFpModel;

///Maximum order of the character ngram model
///@param Type INT
///@param Default 8
extern NSString *const kMGParamLanguageModelNgramOrder;

///Dont crunch words with long lower case strings
///@param Type INT
///@param Default 4
extern NSString *const kMGParamCrunchLeaveLcStrings;

///Threshold at which classify_adapted_pruning_factor starts
///@param Type double
///@param Default -1.0
extern NSString *const kMGParamClassifyAdaptedPruningThreshold;

///Small if lt xht x this
///@param Type double
///@param Default 0.28
extern NSString *const kMGParamFixspSmallOutlinesSize;

///Debug level for wordrec
///@param Type INT
///@param Default 0
extern NSString *const kMGParamWordrecDebugLevel;

///Page seg mode: 0=osd only, 1=auto+osd, 2=auto, 3=col, 4=block, 5=line, 6=word, 7=char (Values from PageSegMode enum in publictypes.h)
///@param Type INT
///@param Default PSM_SINGLE_BLOCK
extern NSString *const kMGParamTesseditPagesegMode;

///1st Trailing punctuation
///@param Type STRING
///@param Default ").,;:?!"
extern NSString *const kMGParamChsTrailingPunct1;

///Minimum length of compound words
///@param Type INT
///@param Default 3
extern NSString *const kMGParamLanguageModelMinCompoundLength;

///Load dawg with punctuation patterns.
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLoadPuncDawg;

///Force word breaks on punct to break long lines in non-space delimited langs
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospForceWordbreakOnPunct;

///Limit use of xht gap with odd small kns
///@param Type double
///@param Default -1
extern NSString *const kMGParamTospDontFoolWithSmallKerns;

///Ile of sizes for xheight guess
///@param Type double
///@param Default 0.75
extern NSString *const kMGParamTextordInitialxIle;

///Use only the first UTF8 step of the given string when computing log probabilities
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamLanguageModelNgramUseOnlyFirstUft8Step;

///Number of linew fits to do
///@param Type INT
///@param Default 12
extern NSString *const kMGParamTextordLmsLineTrials;

///Amount of debug output for bigram correction.
///@param Type INT
///@param Default 0
extern NSString *const kMGParamTesseditBigramDebug;

///Worst certainty for using pending dictionary
///@param Type double
///@param Default 0.0
extern NSString *const kMGParamDocDictPendingThreshold;

///2nd Trailing punctuation
///@param Type STRING
///@param Default ")'`\""
extern NSString *const kMGParamChsTrailingPunct2;

///For smooth factor
///@param Type INT
///@param Default 1
extern NSString *const kMGParamTextordSkewsmoothOffset2;

///No.gaps reqd with 1 large gap to treat as a table
///@param Type INT
///@param Default 40
extern NSString *const kMGParamTospFewSamples;

///Dump char choices
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDumpChoices;

///Tests refer to land/port
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordTestLandscape;

///Non standard number of outlines
///@param Type STRING
///@param Default "ij!?%\":;"
extern NSString *const kMGParamOutlines2;

///Crunch double hyphens?
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditFixHyphens;

///Matcher Debug Level
///@param Type INT
///@param Default 0
extern NSString *const kMGParamMatcherDebugLevel;

///UNLV keep 1Il chars rejected
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamSuspectConstrain1Il;

///Same distance
///@param Type INT
///@param Default 2
extern NSString *const kMGParamChopSameDistance;

///Prune poor adapted results this much worse than best result
///@param Type double
///@param Default 2.5
extern NSString *const kMGParamClassifyAdaptedPruningFactor;

///Allow outline errs in unrejection?
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamDocqualExcuseOutlineErrs;

///Leading punctuation
///@param Type STRING
///@param Default "('`\""
extern NSString *const kMGParamChsLeadingPunct;

///Bring up graphical debugging windows for fragments training
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamClassifyDebugCharacterFragments;

///List of languages to load with this one
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamTesseditLoadSublangs;

///Min blob height/top to include blob top into xheight stats
///@param Type double
///@param Default 0.75
extern NSString *const kMGParamTextordMinBlobHeightFraction;

///Turn on equation detector
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTextordEquationDetect;

///good_quality_doc lte rejection limit
///@param Type double
///@param Default 0.08
extern NSString *const kMGParamQualityRejPc;

///Exposure value follows this pattern in the image filename. The name of the image files are expected to be in the form [lang].[fontname].exp[num].tif
///@param Type STRING
///@param Default ".exp"
extern NSString *const kMGParamApplyboxExposurePattern;

///Display row accumulation
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordShowInitialRows;

///Thresh guess - mult xht by this
///@param Type double
///@param Default 0.28
extern NSString *const kMGParamTospInitGuessXhtMult;

///Multiple of line_size for underline
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamTextordUnderlineWidth;

///Max certaintly variation allowed in a word (in sigma)
///@param Type double
///@param Default 3.0
extern NSString *const kMGParamStopperAllowableCharacterBadness;

///Limit use of xht gap with large kns
///@param Type double
///@param Default 0.19
extern NSString *const kMGParamTospLargeKerning;

///include fixed-pitch heuristics in char segmentation
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamAssumeFixedPitchCharSegment;

///Min credible pixel xheight
///@param Type INT
///@param Default 10
extern NSString *const kMGParamTextordMinXheight;

///Set to 1 for general debug info , to 2 for more details, to 3 to see all the debug messages
///@param Type INT
///@param Default 0
extern NSString *const kMGParamDawgDebugLevel;

///Adaptation decision algorithm for tess
///@param Type INT
///@param Default 0x27
extern NSString *const kMGParamTesseditTessAdaptionMode;

///Display rows after final fitting
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordShowFinalRows;

///Max char x-norm scale ...
///@param Type double
///@param Default 0.325
extern NSString *const kMGParamClassifyMaxNormScaleX;

///Max char y-norm scale ...
///@param Type double
///@param Default 0.325
extern NSString *const kMGParamClassifyMaxNormScaleY;

///Dont chng kn to space next to punct
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospRule9TestPunct;

///Fract of xheight for narrow
///@param Type double
///@param Default 0.3
extern NSString *const kMGParamTospNarrowFraction;

///Each bounding box is assumed to contain ngrams. Only learn the ngrams whose outlines overlap horizontally.
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamApplyboxLearnNgramsMode;

///Small if lt xht x this
///@param Type double
///@param Default 0.6
extern NSString *const kMGParamCrunchSmallOutlinesSize;

///%rej allowed before rej whole doc
///@param Type double
///@param Default 65.00
extern NSString *const kMGParamTesseditRejectDocPercent;

///Penalty for inconsistent punctuation
///@param Type double
///@param Default 0.2
extern NSString *const kMGParamLanguageModelPenaltyPunc;

///ycoord
///@param Type double
///@param Default 99999.99
extern NSString *const kMGParamTestPtY;

///Load dawg with special word bigrams.
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLoadBigramDawg;

///Bad Match Pad (0-1)
///@param Type double
///@param Default 0.15
extern NSString *const kMGParamMatcherBadMatchPad;

///Max iqr/median for linespace
///@param Type double
///@param Default 0.2
extern NSString *const kMGParamTextordLinespaceIqrlimit;

///Debug level
///@param Type INT
///@param Default 1
extern NSString *const kMGParamApplyboxDebug;

///Enable improvement heuristic
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospImproveThresh;

///Dump intermediate images made during page segmentation
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDumpPagesegImages;

///Baseline debug level
///@param Type INT
///@param Default 0
extern NSString *const kMGParamTextordBaselineDebug;

///No.gaps reqd with few cert spaces to use certs
///@param Type INT
///@param Default 20
extern NSString *const kMGParamTospShortRow;

///Score penalty (0.1 = 10%) added if there are subscripts or superscripts in a word, but it is otherwise OK.
///@param Type double
///@param Default 0.125
extern NSString *const kMGParamXheightPenaltySubscripts;

///Take out ~^ early?
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamCrunchEarlyConvertBadUnlvChs;

///Before word crunch?
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamCrunchEarlyMergeTessFails;

///Interpolate across gaps
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamTextordInterpolatingSkew;

///Aspect ratio dot/hyphen test
///@param Type double
///@param Default 1.5
extern NSString *const kMGParamTesseditLowerFlipHyphen;

///Better guess
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospOnlySmallGapsForKern;

///Enable adaption even if the ambiguities have not been seen
///@param Type INT
///@param Default 5
extern NSString *const kMGParamMatcherSufficientExamplesForPrototyping;

///What reduction in badness do we think sufficient to choose a superscript over what we'd thought.  For example, a value of 0.6 means we want to reduce badness of certainty by 40%
///@param Type double
///@param Default 0.97
extern NSString *const kMGParamSuperscriptBetteredCertainty;

///Chop enable
///@param Type BOOL
///@param Default 1
extern NSString *const kMGParamChopEnable;

///As it says
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamCrunchTerribleGarbage;

///Reward punctation joins
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditPreferJoinedPunct;

///Reliable Config Threshold
///@param Type INT
///@param Default 3
extern NSString *const kMGParamMatcherMinExamplesForPrototyping;

///Only preserve wds longer than this
///@param Type INT
///@param Default 2
extern NSString *const kMGParamTesseditPreserveMinWdLen;

///-1 -> All pages, else specifc page to process
///@param Type INT
///@param Default -1
extern NSString *const kMGParamTesseditPageNumber;

///Draw output words
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDisplayOutwords;

///Use word segmentation quality metric
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDontRowrejGoodWds;

///Min Inside Angle Bend
///@param Type INT
///@param Default -50
extern NSString *const kMGParamChopInsideAngle;

///Print test blob information
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamTextordDebugBlob;

///Max cap/xheight
///@param Type double
///@param Default 1.8
extern NSString *const kMGParamTextordAscxRatioMax;

///Display Segmentations
///@param Type INT
///@param Default 0
extern NSString *const kMGParamWordrecDisplaySegmentations;

///Output file for ambiguities found in the dictionary
///@param Type STRING
///@param Default ""
extern NSString *const kMGParamOutputAmbigWordsFile;

///Dont restrict kn->sp fuzzy limit to tables
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTospFuzzyLimitAll;

///if >this fract
///@param Type double
///@param Default 0.85
extern NSString *const kMGParamRejWholeOfMostlyRejectWordFract;

///New row made if blob makes row this big
///@param Type double
///@param Default 1.3
extern NSString *const kMGParamTextordExcessBlobsize;

///Fix blobs that aren't chopped
///@param Type INT
///@param Default 1
extern NSString *const kMGParamRepairUnchoppedBlobs;

///Reject certainty offset
///@param Type double
///@param Default 1.0
extern NSString *const kMGParamStopperPhase2CertaintyRejectionOffset;

///Max baseline shift
///@param Type double
///@param Default 0.00
extern NSString *const kMGParamTextordBlshiftMaxshift;

///Percentile for large blobs
///@param Type double
///@param Default 95
extern NSString *const kMGParamTextordBlobSizeBigile;

///Reject any x-ht lt or eq than this
///@param Type INT
///@param Default 8
extern NSString *const kMGParamMinSaneXHtPixels;

///force associator to run regardless of what enable_assoc is. This is used for CJK where component grouping is necessary.
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamForceWordAssoc;

///Thresh guess - mult kn by this
///@param Type double
///@param Default 2.2
extern NSString *const kMGParamTospInitGuessKnMult;

///Maximum character width-to-height ratio
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamSegsearchMaxCharWhRatio;

///Maximum number of pain points stored in the queue
///@param Type INT
///@param Default 2000
extern NSString *const kMGParamSegsearchMaxPainPoints;

///Use new seam_pile
///@param Type BOOL
///@param Default 1
extern NSString *const kMGParamChopNewSeamPile;

///Max number of blobs a big blob can overlap
///@param Type INT
///@param Default 4
extern NSString *const kMGParamTextordMaxBlobOverlaps;

///Block and Row stats
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTesseditDebugBlockRejection;

///Dont reduce box if the top left is non blank
///@param Type double
///@param Default 0
extern NSString *const kMGParamTospNearLhEdge;

///gap ratio to flip kern->sp
///@param Type double
///@param Default 1.3
extern NSString *const kMGParamTospKernGapFactor2;

///gap ratio to flip kern->sp
///@param Type double
///@param Default 2.5
extern NSString *const kMGParamTospKernGapFactor3;

///gap ratio to flip kern->sp
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamTospKernGapFactor1;

///Debug level for BiDi
///@param Type INT
///@param Default 0
extern NSString *const kMGParamBidiDebug;

///Dont double check
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamRej1IlTrustPermuterType;

///Fix suspected bug in old code
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospOldToBugFix;

///Check/Correct x-height
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamTesseditRedoXheight;

///What constitues done for spacing
///@param Type INT
///@param Default 1
extern NSString *const kMGParamFixspDoneMode;

///Bias skew estimates with line length
///@param Type BOOL
///@param Default TRUE
extern NSString *const kMGParamTextordBiasedSkewcalc;

///Only use within xht gap for wd breaks
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamTospOnlyUseXhtGaps;

///max char width-to-height ratio allowed in segmentation
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamHeuristicMaxCharWhRatio DEPRECATED_ATTRIBUTE;

///Turn on word script consistency permuter
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamPermuteScriptWord DEPRECATED_ATTRIBUTE;

///weight associated with width evidence in combined cost of state
///@param Type double
///@param Default 1000.0
extern NSString *const kMGParamHeuristicWeightWidth DEPRECATED_ATTRIBUTE;

///Depth of blob choice lists to explore when fixed length dawgs are on
///@param Type INT
///@param Default 3
extern NSString *const kMGParamLanguageModelFixedLengthChoicesDepth DEPRECATED_ATTRIBUTE;

///char permutation debug
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamPermuteDebug DEPRECATED_ATTRIBUTE;

///Multiplying factor of current best rate to prune other hypotheses
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamBestratePruningFactor DEPRECATED_ATTRIBUTE;

///Maximum character width-to-height ratio for fixed pitch fonts
///@param Type double
///@param Default 2.0
extern NSString *const kMGParamSegsearchMaxFixedPitchCharWhRatio DEPRECATED_ATTRIBUTE;

///Score multipler for ngram permuter's best choice (only used in the Han script path).
///@param Type double
///@param Default 0.99
extern NSString *const kMGParamSegmentRewardNgramBestChoice DEPRECATED_ATTRIBUTE;

///use new state cost heuristics for segmentation state evaluation
///@param Type BOOL
///@param Default FALSE
extern NSString *const kMGParamUseNewStateCost DEPRECATED_ATTRIBUTE;

///Score multipler for script consistency within a word. Being a 'reward' factor, it should be <= 1. Smaller value implies bigger reward.
///@param Type double
///@param Default 0.95
extern NSString *const kMGParamSegmentRewardScript DEPRECATED_ATTRIBUTE;

///Acceptance decision algorithm
///@param Type INT
///@param Default 5
extern NSString *const kMGParamTesseditOkMode DEPRECATED_ATTRIBUTE;

///Turn on character type (property) consistency permuter
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamPermuteChartypeWord DEPRECATED_ATTRIBUTE;

///Activate character-level n-gram-based permuter
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamNgramPermuterActivated DEPRECATED_ATTRIBUTE;

///Score multipler for char type consistency within a word.
///@param Type double
///@param Default 0.97
extern NSString *const kMGParamSegmentRewardChartype DEPRECATED_ATTRIBUTE;

///weight associated with seam cut in combined cost of state
///@param Type double
///@param Default 0
extern NSString *const kMGParamHeuristicWeightSeamcut DEPRECATED_ATTRIBUTE;

///Load fixed length dawgs (e.g. for non-space delimited languages)
///@param Type BOOL
///@param Default true
extern NSString *const kMGParamLoadFixedLengthDawgs DEPRECATED_ATTRIBUTE;

///Enable new segmentation search path.
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamEnableNewSegsearch DEPRECATED_ATTRIBUTE;

///Turn on fixed-length phrasebook search permuter
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamPermuteFixedLengthDawg DEPRECATED_ATTRIBUTE;

///weight associated with char rating in combined cost of state
///@param Type double
///@param Default 1
extern NSString *const kMGParamHeuristicWeightRating DEPRECATED_ATTRIBUTE;

///base factor for adding segmentation cost into word rating. It's a multiplying factor, the larger the value above 1, the bigger the effect of segmentation cost.
///@param Type double
///@param Default 1.25
extern NSString *const kMGParamHeuristicSegcostRatingBase DEPRECATED_ATTRIBUTE;

///Run only the top choice permuter
///@param Type BOOL
///@param Default false
extern NSString *const kMGParamPermuteOnlyTop DEPRECATED_ATTRIBUTE;

///Debug the whole segmentation process
///@param Type INT
///@param Default 0
extern NSString *const kMGParamSegmentDebug DEPRECATED_ATTRIBUTE;

///incorporate segmentation cost in word rating?
///@param Type BOOL
///@param Default 0
extern NSString *const kMGParamSegmentSegcostRating DEPRECATED_ATTRIBUTE;

#endif
