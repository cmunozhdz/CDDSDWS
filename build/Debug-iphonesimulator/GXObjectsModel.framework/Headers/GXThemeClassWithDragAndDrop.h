//
//  GXThemeClassWithDragAndDrop.h
//  GXFlexibleClient
//
//  Created by willy on 3/12/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@class GXThemeClass;

@protocol GXStyleClassWithDragAndDrop <NSObject>

@property(nullable, nonatomic, strong, readonly) GXStyleClass *startDraggingThemeClass;
@property(nullable, nonatomic, strong, readonly) GXStyleClass *acceptDragThemeClass;
@property(nullable, nonatomic, strong, readonly) GXStyleClass *noAcceptDragThemeClass;
@property(nullable, nonatomic, strong, readonly) GXStyleClass *dragOverThemeClass;

@end

@protocol GXThemeClassWithDragAndDrop <GXStyleClassWithDragAndDrop>
@end

NS_ASSUME_NONNULL_END
