//
//  GXActionUIDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXActionDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, GXActionBarUIPriorityType) {
	GXActionBarUIPriorityLow = 1,
	GXActionBarUIPriorityNormal = 1 << 1,
	GXActionBarUIPriorityHigh = 1 << 2
};

typedef NS_ENUM(uint_least8_t, GXActionBarUIPositionType) {
	GXActionBarUIPositionPriorityBased,
	GXActionBarUIPositionCustom
};

GXActionBarUIPriorityType GXActionBarUIPriorityFromString(NSString * __nullable priorityStr);

typedef NS_ENUM(uint_least8_t, GXActionUIImagePosition) {
    GXActionUIImagePositionAboveText,
    GXActionUIImagePositionBelowText,
    GXActionUIImagePositionBeforeText,
    GXActionUIImagePositionAfterText,
    GXActionUIImagePositionBehindText,
    GXActionUIImagePositionLeft
};

GXActionUIImagePosition GXActionUIImagePositionFromString(NSString * __nullable actionImagePosition, GXActionUIImagePosition defaultValue);

NS_SWIFT_NAME(GXActionUIBaseDescriptorProtocol)
@protocol GXActionUIBaseDescriptor <NSObject>

@property(nullable, nonatomic, strong, readonly) NSString *actionUIThemeClass;
@property(nonatomic, assign, readonly) BOOL actionUIVisible;
@property(nonatomic, assign, readonly) BOOL actionUIEnabled;

@end

NS_SWIFT_NAME(GXActionUIDescriptorProtocol)
@protocol GXActionUIDescriptor <GXActionUIBaseDescriptor>

@property(nullable, nonatomic, strong, readonly) NSString *actionUICaption;
@property(nullable, nonatomic, strong, readonly) NSString *actionUIImage;
@property(nullable, nonatomic, strong, readonly) NSString *actionUIDisabledImage;
@property(nonatomic, assign, readonly) GXActionUIImagePosition actionUIImagePosition;

@optional
@property(nullable, nonatomic, strong, readonly) NSString *actionUICaptionWithoutTranslation;

@end

@protocol GXActionBarUIPositionDescriptor <NSObject>

@property(nonatomic, assign, readonly) GXActionBarUIPositionType actionBarUIPosition;

@end

@protocol GXActionBarUIPositionPriorityBasedDescriptor <GXActionBarUIPositionDescriptor> // actionBarUIPosition == GXActionBarUIPositionPriorityBased

@property(nonatomic, assign, readonly) GXActionBarUIPriorityType actionBarUIPriority;

@end

@protocol GXActionBarUIPositionCustomDescriptor <GXActionBarUIPositionDescriptor> // actionBarUIPosition == GXActionBarUIPositionCustom

@property(nonatomic, assign, readonly) GXHorizontalAlignType actionBarUIHorizontalAlign;
@property(nonatomic, assign, readonly) GXVerticalAlignType actionBarUIVerticalAlign;

@end

NS_SWIFT_NAME(GXActionBarUIDescriptorProtocol)
@protocol GXActionBarUIDescriptor <NSObject>

@property(nonatomic, strong, readonly) id<GXActionBarUIPositionDescriptor> actionBarUIPositionDescriptor;

@end

NS_ASSUME_NONNULL_END
