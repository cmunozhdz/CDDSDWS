//
//  GXSharingServices.h
//  GXCoreUI-iOS
//
//  Created by Marcos Crispino on 24/10/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GXCoreUI/GXSharing.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXSharingService

- (BOOL)shareText:(NSString *)text
			image:(nullable UIImage *)image
		uiContext:(GXUserInterfaceContext *)uiContext
	   completion:(GXSharingCompletionHandler)completion;

@end

@interface GXSharingServices : NSObject

+ (id<GXSharingService>)sharingServiceForType:(GXSharingType)type;

+ (void)registerSharingService:(id<GXSharingService>)service forType:(GXSharingType)type;

NS_ASSUME_NONNULL_END

@end
