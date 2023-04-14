//
//  GXSDObjectModel.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 4/16/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXNamedModelObjectChild.h>

#define kSecurityLevelNONE @"SecurityNone"

NS_ASSUME_NONNULL_BEGIN

@interface GXSDObjectModel : GXNamedModelObjectChild

@property(nonnull, nonatomic, strong, readonly) NSString *name;
@property(nullable, nonatomic, strong, readonly) NSString *securityLevel;
@property(nullable, nonatomic, strong, readonly) NSString *metadataVersion;
@property(nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport;
@property(nullable, nonatomic, strong, readonly) NSString *notificationSettingsPanelName;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (instancetype)initWithName:(NSString *)name
		  instanceProperties:(nullable NSDictionary<NSString *, id> *)instanceProperties
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
