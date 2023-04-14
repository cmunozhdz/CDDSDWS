source '/Users/Shared/Library/GeneXus/GeneXus/CocoaPods'
source 'https://cdn.cocoapods.org/'

project 'CDDSD.xcodeproj'
use_frameworks!

target 'CDDSD' do
  platform :ios, '12.0'

  pod 'lottie-ios', '~> 3.5'
  pod 'OpenCV', '~> 3.2'
end

post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
      config.build_settings['ENABLE_BITCODE'] = 'NO'
    end
  end
end
