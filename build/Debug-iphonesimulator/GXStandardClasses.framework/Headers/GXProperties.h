//
//  GXProperties.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 10/01/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

#import <GXStandardClasses/GXProperty.h>
#import <GXStandardClasses/GXObjectCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXProperties : NSObject <GXEnumerable>

@property (nonatomic, readonly) NSInteger itemCount;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, NSString *> *)dict;

- (void)addKey:(NSString *)key value:(NSString *)value;

- (BOOL)hasKey:(NSString *)key;

- (NSString *)get:(NSString *)key;

- (void)remove:(NSString *)key;

- (void)clear;

- (GXProperty *)first;

- (BOOL)eof;

- (GXProperty *)next;

- (NSString *)toJSONString;
- (BOOL)fromJSONString:(NSString *)jsonStr;
- (BOOL)fromJSONString:(NSString *)jsonStr messages:(nullable GXObjectCollection *)messages NS_SWIFT_NAME(fromJSONString(_:_:));

- (NSDictionary<NSString *, NSString *> *)dictionaryRepresentation;

- (NSNumber *)numberItemCount;

@end

NS_ASSUME_NONNULL_END
