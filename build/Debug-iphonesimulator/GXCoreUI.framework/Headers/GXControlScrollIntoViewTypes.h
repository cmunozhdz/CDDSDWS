//
//  GXControlScrollIntoViewTypes.h
//  GXCoreUI
//
//  Created by Marcos Crispino on 3/8/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

typedef NS_ENUM(NSUInteger, GXVerticalPosition) {
	GXVerticalPositionTop,
	GXVerticalPositionMiddle,
	GXVerticalPositionBottom,
	GXVerticalPositionUndefined = NSUIntegerMax
};

typedef NS_ENUM(NSUInteger, GXHorizontalPosition) {
	GXHorizontalPositionLeft,
	GXHorizontalPositionCenter,
	GXHorizontalPositionRight,
	GXHorizontalPositionUndefined = NSUIntegerMax
};

typedef struct {
	GXVerticalPosition vertical;
	GXHorizontalPosition horizontal;
} GXScrollIntoViewPosition;

extern const GXScrollIntoViewPosition GXScrollIntoViewPositionUndefined;

extern BOOL GXScrollIntoViewPositionIsUndefined(GXScrollIntoViewPosition pos);

