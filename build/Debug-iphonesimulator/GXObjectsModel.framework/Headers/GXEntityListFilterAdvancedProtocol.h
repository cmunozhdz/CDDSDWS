//
//  GXEntityListFilterAdvancedProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 31/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityListFilterAdvancedField;

@protocol GXEntityListFilterAdvanced <NSObject, GXModelObject>

@property(nonatomic, strong, readonly) NSArray<id<GXEntityListFilterAdvancedField>> *entityListFilterAdvancedFields;

@end

typedef NS_ENUM(uint_least8_t, GXEntityListFilterAdvancedFieldType) {
	GXEntityListFilterAdvancedFieldTypeStandard,
	GXEntityListFilterAdvancedFieldTypeRange
};

@protocol GXEntityListFilterAdvancedField <GXEntityDataFieldDescriptor>

@property(nonatomic, assign, readonly) GXEntityListFilterAdvancedFieldType entityListFilterAdvancedFieldType;

@optional
@property(nonatomic, strong, readonly) NSString *entityListFilterAdvancedFieldDescription;

@end


@protocol GXEntityListFilterAdvancedFieldStandard <GXEntityListFilterAdvancedField>

@property(nullable, nonatomic, strong, readonly) id entityListFilterAdvancedFieldDefaultValue;
@property(nonatomic, assign, readonly) BOOL entityListFilterAdvancedFieldAllowAny;

@end

@protocol GXEntityListFilterAdvancedFieldRange <GXEntityListFilterAdvancedField>

@property(nullable, nonatomic, strong, readonly) id entityListFilterAdvancedFieldDefaultFromValue;
@property(nullable, nonatomic, strong, readonly) id entityListFilterAdvancedFieldDefaultToValue;

@end



@protocol GXEntityListFilterAdvancedFieldValue <NSObject>

@property(nonatomic, strong, readonly) id <GXEntityListFilterAdvancedField> entityListFilterAdvancedField;

- (BOOL)isEqualToFieldValue:(id <GXEntityListFilterAdvancedFieldValue>)fieldValue;

@end

@protocol GXEntityListFilterAdvancedFieldStandardValue <GXEntityListFilterAdvancedFieldValue>

@property(nullable, nonatomic, strong, readonly) id entityListFilterAdvancedFieldValue;

@end

@protocol GXEntityListFilterAdvancedFieldRangeValue <GXEntityListFilterAdvancedFieldValue>

@property(nullable, nonatomic, strong, readonly) id entityListFilterAdvancedFieldFromValue;
@property(nullable, nonatomic, strong, readonly) id entityListFilterAdvancedFieldToValue;

@end

NS_ASSUME_NONNULL_END
