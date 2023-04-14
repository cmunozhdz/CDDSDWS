//
//  GXControlAutoHeight.h
//  GXFlexibleClient
//
//  Created by willy on 5/31/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControl.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, GXControlAutoHeightDependencyFlags) {
	GXControlAutoHeightDependencyNone = 0,
	GXControlAutoHeightDependencyData = 1 << 0,
	GXControlAutoHeightDependencyWidth = 1 << 1,
	GXControlAutoHeightDependencyMinimumHeight = 1 << 2,
	GXControlAutoHeightDependencyThemeClass = 1 << 3,
	GXControlAutoHeightDependencyChildControls = 1 << 4,
	GXControlAutoHeightDependencyAll = GXControlAutoHeightDependencyData | GXControlAutoHeightDependencyWidth | GXControlAutoHeightDependencyMinimumHeight | GXControlAutoHeightDependencyThemeClass | GXControlAutoHeightDependencyChildControls,
};

@protocol GXControlAutoHeightDelegate <NSObject>

- (void)autoHeightChangedForControl:(id<GXControl>)control
						 dependency:(GXControlAutoHeightDependencyFlags)flags
						 synchronic:(BOOL)sync;

@end

@protocol GXControlAutoHeight <GXControl>

/*!
 Returns a Boolean value that indicates whether the receiver has any auto height dependency
 
 @result YES if the receiver has any auto height dependency, NO otherwise
 @discussion Must return the same as [self autoHeightDependencyFlags] != GXControlAutoHeightDependencyNone. Notice that additionalHeightToFrame: must return 0 if this method returns NO.
 */
- (BOOL)hasAutoHeightDependencyFlags;

/*!
 Returns the flags which the control height depends on
 
 @result The flags which the control height depends on
 @discussion If this method returns GXControlAutoHeightDependencyNone, then additionalHeightToFrame: must return 0
 */
- (GXControlAutoHeightDependencyFlags)autoHeightDependencyFlags;

/*!
 Calculates the additional height required for the given frame
 
 @param frame The frame against the additional height is calculated
 @result Additional height required for the given frame
 @discussion This method must return 0 if [self hasAutoHeightDependencyFlags] == NO. Notice this method may return a negative value if there is an invisible child control with InvisibleMode = CollapseSpace
 */
- (CGFloat)additionalHeightToFrame:(CGRect)frame;

/*!
 Calculates additional height for the given frame and sets it the control
 
 @param frame The frame against the additional height is calculated
 @result Additional height required for the given frame
 @discussion This method should be called instead of calling additionalHeightToFrame: and then setFrame: if [self hasAutoHeightDependencyFlags] == YES
 */
- (CGFloat)setFrameWithAdditionalHeightToFrame:(CGRect)frame;

/// Delegate which is notified of auto height events
@property(nonatomic, weak) id <GXControlAutoHeightDelegate> autoHeightDelegate;

@optional
/// Same as additionalHeightToFrame: but also receives context options
- (CGFloat)additionalHeightToFrame:(CGRect)frame contextOptions:(nullable NSDictionary<NSString *, id> *)contextOptions;

/// Same as setFrameWithAdditionalHeightToFrame: but also receives context options
- (CGFloat)setFrameWithAdditionalHeightToFrame:(CGRect)frame contextOptions:(nullable NSDictionary<NSString *, id> *)contextOptions;

@end

extern NSString *const GXControlAutoHeightContextOptionExpandableEdgeInsets; // NSValue with UIEdgeInsets
extern NSString *const GXControlAutoHeightContextOptionExpandableEdgeInsetsContentFrameMaxY; // NSNumber with CGFloat

NS_ASSUME_NONNULL_END
