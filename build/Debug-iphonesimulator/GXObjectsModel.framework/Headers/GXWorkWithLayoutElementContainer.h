//
//  GXWorkWithLayoutElementContainer.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElement.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementContainer : GXWorkWithLayoutElement <GXLayoutElementContainer> // Abstract

@property(nullable, nonatomic, strong, readonly) NSArray<__kindof GXWorkWithLayoutElement *> *childElements;
@property(assign, readonly) GXLayoutDimension height;
@property(assign, readonly) GXLayoutDimension width;
@property(assign, readonly) CGFloat fixedHeightSum;
@property(assign, readonly) CGFloat fixedWidthSum;

#pragma mark - Constructor override points

/**
 * Loads child elements from metadata
 * Called by initWithMetadata:context:error:
 */
- (nullable NSArray<__kindof GXWorkWithLayoutElement *> *)initializeChildElementsWithMetadata:(nullable id)metadata
																					  context:(nullable id)context
																						error:(out NSError * __autoreleasing __nullable * __nullable)error __attribute__((swift_error(nonnull_error))); // Abstract

@end

NS_ASSUME_NONNULL_END
