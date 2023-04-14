//
//  GXRegExMatch.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 10/24/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXStandardClasses/GXStringCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXRegExMatch : NSObject

@property (nonatomic, strong) NSString *value;
@property (nonatomic, strong) GXStringCollection *groups;

- (id)initWithValue:(NSString *)value
             groups:(GXStringCollection *)groups;

@end

NS_ASSUME_NONNULL_END
