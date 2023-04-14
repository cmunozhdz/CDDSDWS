//
//  GXWeakWrapper.h
//  GXFoundation
//
//  Created by Fabian Inthamoussu on 16/2/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXWeakWrapper<__covariant ObjectType> : NSObject

@property(nullable, nonatomic, weak) ObjectType innerObject;

- (instancetype)initWithInnerObject:(nullable ObjectType)innerObject NS_DESIGNATED_INITIALIZER;

+ (instancetype)weakWrapperWithInnerObject:(nullable ObjectType)innerObject;

+ (NSArray<ObjectType> *)arrayFilteringWeakReferences:(NSArray<GXWeakWrapper<ObjectType> *> *)weakWapperArray;

@end

NS_ASSUME_NONNULL_END
