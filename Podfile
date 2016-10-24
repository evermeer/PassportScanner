source 'https://github.com/CocoaPods/Specs.git'
use_frameworks!

target 'PassportScanner' do
    platform :ios, '8.0'
    pod 'TesseractOCRiOS'
    pod 'GPUImage'
    pod 'UIImage-Resize'
end

post_install do |installer|
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |config|
            config.build_settings['ENABLE_BITCODE'] = 'NO'
        end
    end
end
