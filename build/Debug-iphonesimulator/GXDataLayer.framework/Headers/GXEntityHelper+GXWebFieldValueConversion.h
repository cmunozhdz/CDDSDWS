//
//  GXEntityHelper+GXWebFieldValueConversion.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 15/1/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXWebFieldValueContersion)

+ (NSString *)webFieldValueForFieldInfo:(id<GXEntityDataFieldInfo>)fieldInfo
							  fromValue:(nullable id)fieldValue;	// useLocalTimezone: NO

+ (NSString *)webFieldValueForFieldInfo:(id<GXEntityDataFieldInfo>)fieldInfo
							  fromValue:(nullable id)fieldValue
					   useLocalTimezone:(BOOL)useLocalTimezone;

@end

NS_ASSUME_NONNULL_END
