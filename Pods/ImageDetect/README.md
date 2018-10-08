# ImageDetect
[![Awesome](https://cdn.rawgit.com/sindresorhus/awesome/d7305f38d29fed78fa85652e3a63e154dd8e8829/media/badge.svg)](https://github.com/sindresorhus/awesome)
[![Version](https://img.shields.io/cocoapods/v/ImageDetect.svg?style=flat)](http://cocoapods.org/pods/ImageDetect)
[![License](https://img.shields.io/cocoapods/l/ImageDetect.svg?style=flat)](http://cocoapods.org/pods/ImageDetect)
[![Platform](https://img.shields.io/cocoapods/p/ImageDetect.svg?style=flat)](http://cocoapods.org/pods/ImageDetect)

ImageDetect is a library developed on Swift. With ImageDetect you can easily detect and crop faces, texts or barcodes in your image with iOS 11 Vision api. It will automatically create new images containing each object found within a given image.

## Example
<br>
<a href="url"><img src="https://github.com/Feghal/ImageDetect/blob/master/Screenshots/1.PNG" align="top" height="550" width="275" ></a>
<a href="url"><img src="https://github.com/Feghal/ImageDetect/blob/master/Screenshots/2.PNG" align="top" height="550" width="275" ></a>
<br>

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements
1) Xcode 9.0 (beta) or higher.
2)  iOS 11.0 (beta) or higher.

## Installation

### CocoaPods

ImageDetect is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'ImageDetect'
```
Then, run the following command:
```ruby
pod install
```
### Manually

1. Drag and Drop it into your project

2. Import `ImageDetect`

3. You are ready to go!

## Usage
Crop your (UIImage or CGImage)
```Swift

// `type` in this method can be face, barcode or text
image.detector.crop(type: .face) { [weak self] result in
    switch result {
        case .success(let croppedImages):
            // When the `Vision` successfully find type of object you set and successfuly crops it.
            print("Found")
        case .notFound:
            // When the image doesn't contain any type of object you did set, `result` will be `.notFound`.
            print("Not Found")
        case .failure(let error):
            // When the any error occured, `result` will be `failure`.
            print(error.localizedDescription)
        }
}
```

## Author

Arthur Sahakyan, feghaldev@gmail.com

## License

ImageDetect is available under the MIT license. See the LICENSE file for more info.
