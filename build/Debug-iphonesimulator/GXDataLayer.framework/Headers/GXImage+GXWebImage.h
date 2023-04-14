//
//  GXImage+GXWebImage.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 24/11/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXWebImageDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXImage (GXWebImage)

- (nullable GXWebImageContext)updatingWebImageContext:(nullable GXWebImageContext)context NS_REFINED_FOR_SWIFT;
- (void)updateWebImageMutableContext:(GXWebImageMutableContext)context NS_REFINED_FOR_SWIFT;

@end

NS_ASSUME_NONNULL_END
