//
//  GXFlexboxLayoutDelegate.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 08/10/2018.
//  Copyright © 2018 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControl.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXFlexboxLayoutDelegate <GXControl>

- (CGSize)gxRequiredSizeGivenSize:(CGSize)size NS_SWIFT_NAME(gxRequiredSize(givenSize:));

@end

@protocol GXFlexboxLayoutBaselineDelegate

- (float)firstBaselineForFlexForBounds:(CGRect)bounds NS_SWIFT_NAME(firstBaselineForFlex(forBounds:));
- (float)lastBaselineForFlexForBounds:(CGRect)bounds NS_SWIFT_NAME(lastBaselineForFlex(forBounds:));

@end

NS_ASSUME_NONNULL_END
