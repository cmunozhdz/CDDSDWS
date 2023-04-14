//
//  GXEntityHelper+GXBinaryDataFieldReference.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 29/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXBinaryDataFieldReference.h>
#import <GXDataLayer/GXStructureDataTypeBinaryDataInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXBinaryDataFieldReference)

+ (BOOL)fieldMayContainBinaryData:(id<GXEntityDataFieldInfo>)fieldInfo
	   sdtBinaryDataInfoContainer:(out GXStructureDataTypeBinaryDataInfoContainer * __nullable * __nullable)sdtBinaryDataInfoContainer;

+ (nullable GXBinaryDataFieldReference *)binaryDataFieldReferenceForFieldDescriptor:(id <GXEntityDataFieldDescriptor>)fieldDesc
																	callerFieldInfo:(nullable id <GXEntityDataFieldInfo>)callerFieldInfo
																			  value:(nullable id)fieldValue
														 sdtBinaryDataInfoContainer:(out GXStructureDataTypeBinaryDataInfoContainer * __nullable * __nullable)sdtBinaryDataInfoContainer;

@end

NS_ASSUME_NONNULL_END
