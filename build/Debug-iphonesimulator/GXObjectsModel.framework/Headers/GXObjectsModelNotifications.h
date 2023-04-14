//
//  GXObjectsModelNotifications.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 26/11/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXSecurityServiceAuthorizationChangedNotification;
extern NSString *const GXSecurityServiceAuthorizationChangedModelKey;
extern NSString *const GXSecurityServiceLoginDidSucceedNotification;

extern NSNotificationName const GXDesignSystemTokenOptionChangedNotification;
extern NSString *const GXDesignSystemTokenOptionChangedNameKey;

extern NSNotificationName const GXImageCurrentVariantChangedNotification;
extern NSString *const GXImageCurrentVariantChangedOldVariantKey; // GXImageVariant

NS_ASSUME_NONNULL_END
