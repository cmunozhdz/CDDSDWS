//
//  GXThreadExpressionEvaluatorHelper.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 16/8/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, GXExpressionThreadRequirement) {
	GXExpressionThreadRequirementAny,
	GXExpressionThreadRequirementMain,
	GXExpressionThreadRequirementBackground,
};


@interface GXThreadExpressionEvaluatorHelper : NSObject

+ (GXExpressionThreadRequirement)expressionThreadRequirement:(id<GXExpression>)expression; // ignoreChildExpressions == NO
+ (GXExpressionThreadRequirement)expressionThreadRequirement:(id<GXExpression>)expression ignoreChildExpressions:(BOOL)ignoreChildExpressions;

+ (void)executeExpressionBlock:(void(^)(void))block
		 withThreadRequirement:(GXExpressionThreadRequirement)threadRequirement
					completion:(void(^ _Nullable)(void))completion;

+ (BOOL)syncExecuteExpressionBlock:(void(^)(void))block
			 withThreadRequirement:(GXExpressionThreadRequirement)threadRequirement; // forceBackgroundOnMainThread == NO
+ (BOOL)syncExecuteExpressionBlock:(void(^)(void))block
			 withThreadRequirement:(GXExpressionThreadRequirement)threadRequirement
	   forceBackgroundOnMainThread:(BOOL)forceBackgroundOnMainThread;

@end

NS_ASSUME_NONNULL_END
