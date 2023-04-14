//
//  GXEntityDataFieldInfoProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataFieldInfo <NSObject>

@property(nonatomic, assign, readonly) GXDataType entityDataFieldInfoDataType;
@property(nonatomic, assign, readonly) BOOL entityDataFieldInfoIsCollection;

@property(nonatomic, assign, readonly) NSUInteger entityDataFieldInfoLength;
@property(nonatomic, assign, readonly) NSUInteger entityDataFieldInfoDecimals;
@property(nonatomic, assign, readonly) GXSpecialDomainType entityDataFieldInfoSpecialDomain NS_REFINED_FOR_SWIFT;
@property(nonatomic, assign, readonly) GXDataDateFormat entityDataFieldInfoDateFormat NS_REFINED_FOR_SWIFT;
@property(nonatomic, assign, readonly) GXDataTimeFormat entityDataFieldInfoTimeFormat NS_REFINED_FOR_SWIFT;
@property(nonatomic, assign, readonly) BOOL entityDataFieldInfoIsPassword;
@property(nullable, nonatomic, strong, readonly) NSString *entityDataFieldInfoInputPicture;
@property(nullable, nonatomic, strong, readonly) NSString *entityDataFieldInfoBasedOnName;
@property(nonatomic, assign, readonly) GXBasedOnType entityDataFieldInfoBasedOnType;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataFieldInfo> entityDataFieldInfoBasedOnInfo;
@property(nonatomic, strong, readonly) id<GXModelObject> entityDataFieldInfoModelObject;

@optional

/*!
 Field Info for the collection item
 
 @result An instance of id <GXEntityDataFieldInfo> that returns the same as self on all methods but entityDataFieldInfoIsCollection == NO
 @discussion Required if entityDataFieldInfoIsCollection == YES.
 */
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataFieldInfo> entityDataFieldInfoCollectionItemFieldInfo;

@end

NS_ASSUME_NONNULL_END
