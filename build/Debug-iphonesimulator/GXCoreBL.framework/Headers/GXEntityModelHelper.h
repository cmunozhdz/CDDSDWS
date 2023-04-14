//
//  GXEntityModelHelper.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 18/1/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityModelHelper : NSObject

+ (nullable GXWorkWithDetail *)workWithComponentForWorkWithModel:(GXWorkWithModel *)wwModel
										 workWithComponentString:(nullable NSString *)wwComponentString;

+ (nullable GXWorkWithDetail *)firstComponentFromModel:(GXWorkWithModel *)wwModel;

@end

NS_ASSUME_NONNULL_END
