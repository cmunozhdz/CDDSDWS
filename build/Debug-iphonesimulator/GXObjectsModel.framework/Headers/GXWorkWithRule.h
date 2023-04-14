//
//  GXWorkWithRule.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 2/25/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXModelObjectChild.h>

typedef NS_ENUM(uint_least8_t, GXWorkWithRuleType) {
    GXWorkWithRuleTypePrompt
};

@interface GXWorkWithRule : GXModelObjectChild

/**
 * Abstract property, must override
 */
@property (nonatomic, assign, readonly) GXWorkWithRuleType ruleType;

@end
