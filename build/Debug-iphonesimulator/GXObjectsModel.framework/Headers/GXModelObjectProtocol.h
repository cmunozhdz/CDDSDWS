//
//  GXModelObjectProtocol.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 12/1/22.
//  Copyright © 2022 GeneXus. All rights reserved.
//

@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@class GXModel;

@protocol GXModelObject

@property(nonatomic, nullable, readonly) GXModel* gxModel;

@end

NS_ASSUME_NONNULL_END
