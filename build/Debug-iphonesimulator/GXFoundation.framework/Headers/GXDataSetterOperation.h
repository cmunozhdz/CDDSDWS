//
//  GXDataSetterOperation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/07/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXDataSetterOperation : NSOperation

@property(nullable, nonatomic, weak) NSObject *source;
@property(nullable, nonatomic, weak) NSObject *destination;
@property(nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *dataKeys;

@end

NS_ASSUME_NONNULL_END
