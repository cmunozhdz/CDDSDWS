//
//  GXControlBaseWithLayout.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 19/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlBase.h>
#import <GXCoreUI/GXViewLayoutDelegationProtocol.h>

@interface GXControlBaseWithLayout : GXControlBase <GXViewLayoutDelegate>

/**
 * Called on [_mainView layoutSubviews] when the _mainView conforms to GXViewWithLayoutDelegation
 */
- (void)layoutControls;

#pragma mark - Abstract

/**
 * Layout content views loaded in loadContentViewsWithContentFrame:intoContainerView:
 * Called on layoutControls
 */
- (void)layoutContentViewsWithContentFrame:(CGRect)contentFrame;

@end
