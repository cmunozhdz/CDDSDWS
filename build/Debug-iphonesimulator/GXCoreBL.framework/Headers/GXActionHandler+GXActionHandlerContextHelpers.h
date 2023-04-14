//
//  GXActionHandler+GXActionHandlerContextHelpers.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 15/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreBL/GXActionHandler.h>

@interface GXActionHandler (GXActionHandlerContextHelpers)

@property(nullable, nonatomic, strong, readonly) GXUserInterfaceContext *optionalUserInterfaceContext;

@end
