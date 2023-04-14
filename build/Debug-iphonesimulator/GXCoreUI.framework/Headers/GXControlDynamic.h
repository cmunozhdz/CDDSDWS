//
//  GXControlDynamic.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 12/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlWithData.h>

@protocol GXEntityData;
@class GXEntityDataFieldDynamicComboProvider;

@protocol GXControlDynamic <GXControlWithData>

@property(nonatomic, strong, readonly) GXEntityDataFieldDynamicComboProvider *controlDynamicProvider;

- (void)controlDynamicReload;

- (id<GXDynamicDataService>)controlDynamicService;

@end
