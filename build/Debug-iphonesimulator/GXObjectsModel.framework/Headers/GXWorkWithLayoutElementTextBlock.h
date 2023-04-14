//
//  GXWorkWithLayoutElementTextBlock.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElement.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementTextBlock : GXWorkWithLayoutElement <GXLayoutElementTextBlock>

@property(nullable, nonatomic, strong, readonly) NSString *translatedCaption;
@property(nonatomic, assign, readonly) BOOL autoGrow;

@end

NS_ASSUME_NONNULL_END
