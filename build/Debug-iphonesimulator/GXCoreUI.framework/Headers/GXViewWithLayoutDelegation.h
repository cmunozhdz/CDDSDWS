//
//  GXViewWithLayoutDelegation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/03/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControl.h>
#import <GXCoreUI/GXScrollView.h>
#import <GXCoreUI/GXViewLayoutDelegationProtocol.h>

@interface GXViewWithLayoutDelegation : UIView <GXViewWithLayoutDelegation, GXControlView>
@end

@interface GXScrollViewWithLayoutDelegation : GXScrollView <GXViewWithLayoutDelegation, GXControlView>
@end
