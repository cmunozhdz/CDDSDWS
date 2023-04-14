//
//  GXPHPickerResultHelper.h
//  GXCoreUI-iOS
//
//  Created by Marcos Crispino on 7/14/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

@import Foundation;
@import PhotosUI;

NS_ASSUME_NONNULL_BEGIN

@interface GXPHPickerResultHelper: NSObject

+ (void)getMediaURLFromPickerResult:(PHPickerResult *)result
						 completion:(void (^)(NSURL * _Nullable, NSError * _Nullable))completion API_AVAILABLE(ios(14));

@end

NS_ASSUME_NONNULL_END
