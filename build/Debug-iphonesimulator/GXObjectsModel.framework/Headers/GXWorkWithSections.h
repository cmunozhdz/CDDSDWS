//
//  GXWorkWithSections.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithSection.h>

@class GXWorkWithModel;
@class GXWorkWithLevel;
@class GXWorkWithDetail;

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithSections : NSObject

@property(nullable, nonatomic, weak, readonly) GXWorkWithModel *workWithModel;
@property(nullable, nonatomic, weak, readonly) GXWorkWithLevel *workWithLevel;
@property(nullable, nonatomic, weak, readonly) GXWorkWithDetail *workWithDetail;

@property(nonatomic, strong, readonly) NSArray<GXWorkWithSection *> *sections;

- (instancetype)initWithSections:(nullable NSArray<GXWorkWithSection *> *)sections NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


@end

NS_ASSUME_NONNULL_END
