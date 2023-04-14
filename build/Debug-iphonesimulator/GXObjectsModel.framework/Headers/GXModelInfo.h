//
//  GXModelInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import Foundation;

#define kGXModelInfoRequiredCompatibilityVersion 238 // Increment when models change in order to reload from metadata instead of cache

@interface GXModelInfo : NSObject <NSCoding>

@property(readonly) NSUInteger compatibilityVersion;
@property(readonly) NSUInteger compatibilityDeviceSystemVersion;
@property(readonly) NSUInteger localMetadataVersion;
@property(readonly) unsigned short architectureWordSize;

- (BOOL)isModelInfoCompatible;

@end
