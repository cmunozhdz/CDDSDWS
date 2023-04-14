//
//  GXModelObjectChild.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 17/9/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import GXFoundation;
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXModelObjectChild : NSObject <NSCoding, GXModelObject>

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
