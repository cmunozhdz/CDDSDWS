//
//  GXMultiColumnWheelHelper.h
//  GXFlexibleClient
//
//  Created by Panizza Alejandro on 5/8/12.
//  Copyright (c) 2012 None. All rights reserved.
//

@import GXDataLayer;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXWheelColumnType) {
	GXWheelColumnTypeString,
    GXWheelColumnTypeNumeric,
    GXWheelColumnTypeFloat,
    GXWheelColumnTypeImage
};

@interface GXWheelValue : NSObject

/// Index of the selected item
@property (nonatomic, assign) NSInteger selectedRowIndex;

/// Returns the description of the selected value
@property (nonatomic, strong, readonly) NSString *selectedValueDescription;

/// Number of items in the wheel's value range
@property (nonatomic, assign, readonly) NSInteger rangeItemCount;

/**
 Returns the string representation for the value in the given row
 */
- (NSString *)stringValueForItemAtRow:(NSInteger)row;

/**
 Returns the printable description (value and unit) for the given row
 */
- (NSString *)descriptionForItemAtRow:(NSInteger)row;

@end

#pragma mark -

@interface GXMultiColumnWheelHelper : NSObject

// Value reading

+ (NSArray<GXWheelValue *> *)readValueForEntityData:(id<GXEntityData>)entityData
									 fieldSpecifier:(nullable NSString *)fieldSpecifier
									fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc;

// Converting to human-readable description

+ (NSString *)stringDescriptionForEntityData:(id<GXEntityData>)entityData
							  fieldSpecifier:(NSString *)fieldSpecifier
							 fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc;

+ (NSString *)stringDescriptionForJsonString:(NSString *)jsonStr;

// Converting to string representation

+ (NSString *)stringRepresentationForMultiColumnWheelValues:(NSArray *)value;

@end

NS_ASSUME_NONNULL_END
