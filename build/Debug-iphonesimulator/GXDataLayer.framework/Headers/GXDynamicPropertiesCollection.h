//
//  GXDynamicPropertiesCollection.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 12/9/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXDataLayer/GXControlDynamicProperty.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXDynamicPropertiesCollection : NSObject

- (instancetype)initWithProperties:(NSArray<__kindof GXControlDynamicPropertyBase *> *)properties NS_DESIGNATED_INITIALIZER;

@property(nonatomic, strong, readonly) NSArray<__kindof GXControlDynamicPropertyBase *> *properties;

@end

NS_ASSUME_NONNULL_END
