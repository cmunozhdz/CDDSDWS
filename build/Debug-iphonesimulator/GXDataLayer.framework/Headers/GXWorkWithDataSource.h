//
//  GXWorkWithDataSource.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithDataSourceBase : NSObject <GXEntityDataSourceLevelDescriptor, GXModelObject>

- (instancetype)initWithWorkWithModel:(GXWorkWithModel *)model
								 data:(nullable GXWorkWithDataBase *)data NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) GXWorkWithModel *workWithModel;
@property(nullable, nonatomic, strong, readonly) GXWorkWithDataBase *workWithDataBase;

@end

@interface GXWorkWithDataSourceSublevel: GXWorkWithDataSourceBase <GXEntityDataSourceSublevelDescriptor>

- (instancetype)initWithParentLevel:(GXWorkWithDataSourceBase *)parentLevel
					   sublevelData:(GXWorkWithDataSublevel *)sublevelData NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithWorkWithModel:(GXWorkWithModel *)model
								 data:(nullable GXWorkWithDataBase *)data NS_UNAVAILABLE;

@end

@interface GXWorkWithDataSource : GXWorkWithDataSourceBase <GXEntityDataSourceDescriptor>

- (instancetype)initWithWorkWithModel:(GXWorkWithModel *)model
								 data:(nullable GXWorkWithData *)data
						   parameters:(nullable GXWorkWithParameters *)parameters NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithWorkWithModel:(GXWorkWithModel *)model
								 data:(nullable GXWorkWithDataBase *)data NS_UNAVAILABLE;

@property(nullable, nonatomic, strong, readonly) GXWorkWithData *workWithData;
@property(nullable, nonatomic, strong, readonly) GXWorkWithParameters *workWithParameters;

@end


@interface GXWorkWithCollectionDataSource : GXWorkWithDataSource <GXCollectionEntityDataSourceDescriptor>

@end

@interface GXWorkWithSingleItemDataSource : GXWorkWithDataSource <GXSingleItemEntityDataSourceDescriptor>

@end

NS_ASSUME_NONNULL_END
