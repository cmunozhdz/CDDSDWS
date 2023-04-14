//
//  GXDescriptionModelObjectChild.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 18/9/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXDescriptionElement.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXDescriptionModelObjectChild : GXDescriptionElement <GXModelObject>

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc NS_UNAVAILABLE;
- (instancetype)initWithName:(nullable NSString *)name NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
