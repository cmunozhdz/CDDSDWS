//
//  GXControlSingleContainerBase.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 28/07/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlContainerBase.h>
#import <GXCoreUI/GXControlTable.h>

@interface GXControlSingleContainerBase : GXControlContainerBase <GXViewLayoutDelegate, GXControlAutoHeight>

@property(nonatomic, strong, readonly) GXControlTable *tableControl;
@property(nonatomic, strong, readonly) GXControlTable *loadedTableControl; // Same as tableControl but does not trigger control creation

#pragma mark - Abstract methods

/*
 * Creates a new table control
 * Called in createControl
 */
- (GXControlTable *)newTableControl;

/**
 * Returns the edge insets required to be applied to the content frame
 * Default implementation returns GXLayoutQuadDimensionZero
 */
- (GXLayoutQuadDimension)innerTableRequiredEdgeInsetsToContentFrame;

/*
 * Called on [self.view layoutSubviews]
 */
- (void)layoutControls;

#pragma mark - Override points

/// Called after newTableControl
- (void)initializeNewTableControl;

/**
 * Returns the class for mainView
 */
- (Class)viewWithLayoutDelegationClass;

/*!
 Returns <tt>YES</tt> if it should collapse when inner table control collapses (additionalHeightToFrame: negative height)
 
 @discussion Called in additionalHeightToFrame. Default implementation returns <tt>NO</tt>.
 */
- (BOOL)shouldCollapseWithTableControl;

@end
