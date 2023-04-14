//
//  AppDelegate_Shared.h
//  GXUIApplication
//
//  Created by José Echagüe on 12/9/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import Foundation;
@import GXCoreUI;

NS_ASSUME_NONNULL_BEGIN

@interface AppDelegate_Shared: NSObject

// #deprecated: 2022-06-28: trunk; #to-remove: ??
@property(nonatomic, readwrite, strong) GXWindow *gxWindow __attribute__((deprecated("Use GXExecutionEnvironment instead")));
// #deprecated: 2022-06-28: trunk; #to-remove: ??
@property(nullable, nonatomic, readwrite, strong) GXPreferencesViewController *preferenceViewController __attribute__((deprecated));
@property(nonatomic, readwrite, strong) NSDictionary *gxData;

@end

NS_ASSUME_NONNULL_END
