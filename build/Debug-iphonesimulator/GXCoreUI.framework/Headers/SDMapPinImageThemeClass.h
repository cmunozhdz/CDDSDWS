//
//  SDMapPinImageThemeClass.h
//  GXUCMaps
//
//  Created by Marcos Crispino on 13/1/15.
//
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

extern GXStyleClassPropertyName GXStyleClassPropertyNameSDMapPinImageHeight;
extern GXStyleClassPropertyName GXStyleClassPropertyNameSDMapPinImageWidth;
extern GXStyleClassPropertyName GXStyleClassPropertyNameSDMapPinImageScaleType;

@interface SDMapPinImageThemeClass : GXThemeClass

+ (NSInteger)pinImageHeightWithStyleClass:(nullable GXStyleClass *)styleClass;
+ (NSInteger)pinImageWidthWithStyleClass:(nullable GXStyleClass *)styleClass;
+ (GXImageScaleType)pinImageScaleTypeWithStyleClass:(nullable GXStyleClass *)styleClass;

@property (nonatomic, assign, readonly) NSInteger pinImageHeight;
@property (nonatomic, assign, readonly) NSInteger pinImageWidth;
@property (nonatomic, assign, readonly) GXImageScaleType pinImageScaleType;

@end

NS_ASSUME_NONNULL_END
