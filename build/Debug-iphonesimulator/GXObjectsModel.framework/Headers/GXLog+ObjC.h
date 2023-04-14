//
//  GXLog+ObjC.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 11/11/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXLog (ObjC)

+ (void)logWithFormat:(NSString *)format arguments:(va_list)args;
+ (void)logWithFormat:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END
