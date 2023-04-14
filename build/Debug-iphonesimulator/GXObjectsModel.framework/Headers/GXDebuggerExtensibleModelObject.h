//
//  GXDebuggerExtensibleModelObject.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/11/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXDebuggerExtensibleModelObject <NSObject>

@property(nonatomic, strong, readonly) id <GXMutableCodingPropertiesObject> debuggerProperties;

- (void)loadDebuggerPropertiesFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata
								   context:(nullable NSDictionary<NSString *, id> *)context;

@end

NS_ASSUME_NONNULL_END
