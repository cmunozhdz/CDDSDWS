//
//  GXWorkWithLevel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXDescriptionElement.h>
#import <GXObjectsModel/GXWorkWithDetail.h>

NS_ASSUME_NONNULL_BEGIN

@class GXWorkWithModel;

@interface GXWorkWithLevel : GXDescriptionElement <GXModelObject>

@property(nonatomic, strong, readonly) NSString *name;
@property(nullable, nonatomic, weak, readonly) GXWorkWithModel *workWithModel;
@property(nullable, nonatomic, strong, readonly) GXWorkWithDetail *list;
@property(nullable, nonatomic, strong, readonly) GXWorkWithDetail *detail;

- (instancetype)initWithName:(NSString *)name
				 description:(nullable NSString *)desc
						list:(nullable GXWorkWithDetail *)list
					  detail:(nullable GXWorkWithDetail *)detail NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
