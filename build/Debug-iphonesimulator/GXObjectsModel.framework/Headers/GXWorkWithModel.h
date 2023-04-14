//
//  GXWorkWithModel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 05/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXSDObjectModel.h>
#import <GXObjectsModel/GXWorkWithLevel.h>
#import <GXObjectsModel/GXWorkWithActions.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithModel : GXSDObjectModel

@property(nullable, nonatomic, strong, readonly) NSString *businessComponent;
@property(nonatomic, strong, readonly) NSArray<GXWorkWithLevel *> *levels;
@property(nullable, nonatomic, strong, readonly) GXWorkWithActions *notifications;

- (instancetype)initWithName:(NSString *)name
		   businessComponent:(nullable NSString *)businessComponent
					  levels:(nullable NSArray<GXWorkWithLevel *> *)levels
			   notifications:(nullable GXWorkWithActions *)notifications
		  instanceProperties:(nullable NSDictionary<NSString *, id> *)instanceProperties
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithModel (Helpers)

- (nullable GXWorkWithLevel *)workWithLevelRoot;
- (nullable GXWorkWithLevel *)workWithLevelForName:(NSString *)levelName;

- (nullable GXWorkWithDetail *)workWithComponentFromString:(nullable NSString *)wwComponentString;
@property(nullable, nonatomic, strong, readonly) GXWorkWithDetail *workWithFirstComponent;

@end

NS_ASSUME_NONNULL_END
