//
//  GXWorkWithDataSublevel.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 11/5/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithDataBase.h>

NS_ASSUME_NONNULL_BEGIN

@class GXWorkWithData;

@interface GXWorkWithDataSublevel : GXWorkWithDataBase <GXEntityDataFieldDescriptor>

@property(nullable, nonatomic, weak, readonly) GXWorkWithDataBase *parentLevel;
@property(nullable, nonatomic, weak, readonly) GXWorkWithData *rootLevel;
@property(nonnull, nonatomic, strong, readonly) NSString *level;

@end

NS_ASSUME_NONNULL_END
