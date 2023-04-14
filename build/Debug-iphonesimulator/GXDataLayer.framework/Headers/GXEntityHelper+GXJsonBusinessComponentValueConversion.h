//
//  GXEntityHelper+GXJsonBusinessComponentValueConversion.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;
#import <GXDataLayer/GXBinaryDataFieldReference.h>

extern NSString *const GXBusinessComponentEntityMD5HashJsonFieldKey;

@interface GXEntityHelper (GXJsonBusinessComponentValueConversion)

+ (NSMutableDictionary *)jsonBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel
										   fromData:(id <GXBusinessComponentLevelEntityData>)data;

+ (NSMutableDictionary *)jsonBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel
										   fromData:(id <GXBusinessComponentLevelEntityData>)data
						   binaryDataFieldReference:(GXCompositeBinaryDataFieldReference **)binaryDataFieldRef;

+ (NSString *)jsonStringBusinessComponent:(GXBusinessComponentModel *)bcModel
								 fromData:(id <GXBusinessComponentLevelEntityData>)data;

@end
