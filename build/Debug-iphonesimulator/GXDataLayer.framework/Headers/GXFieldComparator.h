//
//  GXFieldComparator.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 25/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef BOOL (GXFieldComparatorFunction)(id _Nullable value1, id _Nullable value2);

@protocol GXEntityComparator <NSObject>

- (BOOL)compareEntity:(nullable id)entity1 toEntity:(nullable id)entity2;

@end

@interface GXFieldComparator : NSObject <GXEntityComparator> {
	NSString *_fieldKey;
	GXFieldComparatorFunction *_fieldComparatorFunction;
}

@property (nonatomic, strong, readonly) NSString *fieldKey;
@property (nonatomic, readonly) GXFieldComparatorFunction *fieldComparatorFunction;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFieldKey:(NSString *)fieldKey; // uses compareObjects FieldComparator

- (instancetype)initWithFieldKey:(NSString *)fieldKey
				 fieldComparator:(GXFieldComparatorFunction)fieldComparatorFunction NS_DESIGNATED_INITIALIZER;

@end

@interface GXDictionaryFieldComparator : GXFieldComparator
@end

@interface GXCompoundFieldComparator : NSObject <GXEntityComparator> {
	NSArray<id<GXEntityComparator>> *_fieldComparators;
}

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFieldComparators:(NSArray<id<GXEntityComparator>> *)comparators NS_DESIGNATED_INITIALIZER;

@end

BOOL compareObjects(id _Nullable object1, id _Nullable object2);
BOOL compareDates(NSDate * _Nullable date1, NSDate * _Nullable date2);
BOOL compareHoursMinutes(NSDate * _Nullable date1, NSDate * _Nullable date2);
BOOL compareDatesAndHoursMinutes(NSDate * _Nullable date1, NSDate * _Nullable date2);
BOOL compareFirstLetter(NSString * _Nullable string1, NSString * _Nullable string2);

NSString *firstLetterTitle(NSString * _Nullable aString);

NS_ASSUME_NONNULL_END
