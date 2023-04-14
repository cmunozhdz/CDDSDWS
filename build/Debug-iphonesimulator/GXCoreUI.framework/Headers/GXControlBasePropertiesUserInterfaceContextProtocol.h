//
//  GXControlBasePropertiesUserInterfaceContextProtocol.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 14/02/2020.
//  Copyright © 2020 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControl.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlBaseProperties;

@protocol GXControlBasePropertiesUserInterfaceContext <GXUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) id <GXControlBaseProperties> userInterfaceContextControlBaseProperties;

@end

NS_ASSUME_NONNULL_END
