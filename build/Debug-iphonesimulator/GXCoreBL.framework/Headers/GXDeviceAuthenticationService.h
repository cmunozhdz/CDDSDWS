//
//  GXDeviceAuthenticationService.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 23/05/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXDeviceAuthenticationService <NSObject>

@property(nonatomic, readonly) BOOL isBiometricsAvailable;

@property(nullable, nonatomic, readonly) NSString *biometricsDescription;

@end

NS_ASSUME_NONNULL_END
