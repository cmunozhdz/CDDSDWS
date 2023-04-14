//
//  GXInheritedConnectivitySupportResolver.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXOptionalInheritedConnectivitySupportResolver <NSObject>

@optional
- (GXConnectivitySupportType)resolvedInheritedConnectivitySupportForObject:(id)sender;

@end

@protocol GXOptionalConditionalInheritedConnectivitySupportResolver <GXOptionalInheritedConnectivitySupportResolver>

@optional
- (BOOL)canResolveInheritedConnectivitySupportForObject:(id)sender;

@end



@protocol GXInheritedConnectivitySupportResolver <GXOptionalInheritedConnectivitySupportResolver>

@required
- (GXConnectivitySupportType)resolvedInheritedConnectivitySupportForObject:(id)sender;

@end

@protocol GXConditionalInheritedConnectivitySupportResolver <GXInheritedConnectivitySupportResolver, GXOptionalConditionalInheritedConnectivitySupportResolver>

@required
- (BOOL)canResolveInheritedConnectivitySupportForObject:(id)sender;

@end

NS_ASSUME_NONNULL_END
