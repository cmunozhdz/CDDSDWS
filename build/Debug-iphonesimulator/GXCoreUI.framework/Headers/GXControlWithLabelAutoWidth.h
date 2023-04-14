//
//  GXControlWithLabelAutoWidth.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXFoundation;
#import <GXCoreUI/GXControl.h>

@protocol GXControlWithLabelAutoWidth <GXControl>

@property(nonatomic, assign, readonly) GXLayoutLabelPositionType labelPosition;
@property(nonatomic, assign, readwrite) CGFloat labelAutoWidth;

- (CGFloat)labelWidth;

@end
