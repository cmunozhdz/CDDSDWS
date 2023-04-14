//
//  GXTextInputHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 24/07/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import UIKit;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXTextInputHelper : NSObject

+ (BOOL)shouldReplaceTextInput:(id <UITextInput>)textInput
			 charactersInRange:(NSRange)range
					withString:(NSString *)string
				  forFieldInfo:(nullable id<GXEntityDataFieldInfo>)fieldInfo
		allowedReplacementText:(out NSString * __nullable __autoreleasing * __nullable)allowedReplacementText;

+ (void)applyEntityDataFieldProperties:(id <GXEntityDataFieldInfo>)fieldInfo
						   toTextField:(id <UITextInputTraits>)textField;
+ (void)applyEntityDataFieldProperties:(id <GXEntityDataFieldInfo>)fieldInfo
					 isSecureTextEntry:(BOOL)isPassword
						   toTextField:(id <UITextInputTraits>)textField;

@end

NS_ASSUME_NONNULL_END
