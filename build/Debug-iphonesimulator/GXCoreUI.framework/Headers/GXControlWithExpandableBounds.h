//
//  GXControlWithExpandableBounds.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 14/5/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

#import <GXCoreUI/GXControl.h>

@protocol GXControlWithExpandableBounds <GXControl>

@property(nonatomic, assign, readonly) GXLayoutExpandableBounds expandableBounds;
@property(nonatomic, assign, readonly) GXLayoutExpandDirection expandDirection; // layoutElementExpandableBounds == None -> layoutElementExpandDirection == None
@property(nonatomic, assign, readonly) GXLayoutExpandLimit expandLimit;

@property(nonatomic, assign) UIEdgeInsets expandableEdgeInsets;

@end
