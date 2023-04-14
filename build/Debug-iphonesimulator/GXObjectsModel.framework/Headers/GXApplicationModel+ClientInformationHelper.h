//
//  GXApplicationModel+ClientInformationHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 22/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXApplicationModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXApplicationModel (ClientInformationHelper)

@property(nonatomic, strong, readonly) NSString *applicationPlatformName;
@property(nonatomic, strong, readonly) NSString *applicationEntryPointIdentifier;
@property(nonatomic, strong, readonly) NSString *applicationEntryPointVersionCode;
@property(nonatomic, strong, readonly) NSString *applicationEntryPointVersionName;
+ (NSString *)applicationEntryPointIdentifier:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (NSString *)applicationEntryPointVersionCode:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (NSString *)applicationEntryPointVersionName:(id<GXApplicationEntryPoint>)appEntryPoint;

@end

NS_ASSUME_NONNULL_END
