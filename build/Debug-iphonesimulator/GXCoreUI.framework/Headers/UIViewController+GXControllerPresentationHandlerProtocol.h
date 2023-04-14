//
//  UIViewController+GXControllerPresentationHandlerProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import UIKit;
@import GXObjectsModel;
@import GXObjectsModel.Swift;

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (GXControllerPresentationHandlerProtocol)

- (BOOL)gxDismissWithPresentationHandler:(nullable id <GXControllerPresentationHandlerProtocol>)presentationHandler
								animated:(BOOL)animated
							  completion:(nullable void (^)(void))completion;

@end

NS_ASSUME_NONNULL_END
