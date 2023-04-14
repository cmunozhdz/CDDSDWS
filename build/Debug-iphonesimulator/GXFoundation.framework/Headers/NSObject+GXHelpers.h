//
//  NSObject+GXHelpers.h
//  GXFoundation
//
//  Created by Fabian Inthamoussu on 21/04/2020.
//  Copyright © 2020 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (GXHelpers)

/*!
Checks if the given reference matches self

@param reference Reference to match against self
@param dealloc If true if called on [self dealloc], false otherwise
@result Returns reference == self || (dealloc && reference = nil)
*/
- (BOOL)gxWeakReferenceMatchesSelf:(nullable id)reference onDealloc:(BOOL)dealloc NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
