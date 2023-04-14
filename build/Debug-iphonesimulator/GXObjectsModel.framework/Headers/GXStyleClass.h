//
//  GXStyleClass.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 11/3/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXNamedElement.h>
#import <GXObjectsModel/GXStyleClassPropertyName.h>

@class GXStyleKBObject;

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleClass : GXNamedElement

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(nullable NSString *)name NS_UNAVAILABLE;

@property(nullable, nonatomic, strong, readonly) NSDictionary<GXStyleClassPropertyName, id> *propertiesValuesByName;

@end

NS_ASSUME_NONNULL_END
