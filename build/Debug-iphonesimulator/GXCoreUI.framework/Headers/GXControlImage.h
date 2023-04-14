//
//  GXControlImage.h
//  GXFlexibleClient
//
//  Created by willy on 5/17/11.
//  Copyright 2011 Artech. All rights reserved.
//

#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlAutoHeight.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXControlEditableWithLabelSingleEditorViewBase.h>

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
@interface GXControlImage : GXControlEditableWithLabelSingleEditorViewBase <GXControlAutoHeight>
#else
@interface GXControlImage : GXControlEditableWithLabelSingleEditorViewBase
#endif // !TARGET_OS_WATCH
{
	BOOL _syncImageChange;
}

#if !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) UIImageView *imageView;
@property(nullable, nonatomic, strong, readonly) UIImageView *imageUIElement; // Sames as self.imageView property for common code (iOS / watchOS)
#else
@property(nonatomic, strong, readonly) WKInterfaceImage *interfaceImage;
@property(nullable, nonatomic, strong, readonly) WKInterfaceImage *imageUIElement; // Same as self.interfaceImage property for common code (iOS / watchOS)
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
