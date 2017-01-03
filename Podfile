source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'
use_frameworks!

target 'PassportScanner' do
   pod 'TesseractOCRiOS'
   pod 'UIImage-Resize'
   pod 'GPUImage'
   pod 'EVGPUImage2'
end

post_install do |installer|
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |config|
            config.build_settings['ENABLE_BITCODE'] = 'NO'
        end
    end
end
