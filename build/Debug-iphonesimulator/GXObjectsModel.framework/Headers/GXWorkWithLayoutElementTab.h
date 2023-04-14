//
//  GXWorkWithLayoutElementTab.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElement.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementTab : NSObject <NSCoding, GXLayoutElementTab>

@property(nonatomic, strong, readonly) GXWorkWithLayoutElement *tabElement;

- (instancetype)initWithControlName:(nullable NSString *)controlName
							caption:(nullable NSString *)caption
						imageString:(nullable NSString *)imageStr
			  unselectedImageString:(nullable NSString *)unselImageStr
					  imagePosition:(GXActionUIImagePosition)imagePosition
							element:(GXWorkWithLayoutElement *)element
			unselectedClassFullName:(nullable NSString *)unselClassFullName
			  selectedClassFullName:(nullable NSString *)selClassFullName
							visible:(BOOL)visible
							enabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
