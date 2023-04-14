//
//  GXStructureDataTypeBinaryDataInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/05/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXDataLayer/GXStructureDataTypeBinaryDataLevelMemberInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStructureDataTypeBinaryDataInfo : NSObject

- (instancetype)initWithSDTBasedOnName:(NSString *)sdtBasedOnName
						  sdtFieldInfo:(id<GXEntityDataSDTFieldInfo>)sdtFieldInfo
				   levelBinaryDataInfo:(GXStructureDataTypeBinaryDataLevelInfo *)levelBinaryDataInfo NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) NSString *sdtBasedOnName;
@property(nonatomic, strong, readonly) id<GXEntityDataSDTFieldInfo> sdtFieldInfo;
@property(nonatomic, strong, readonly) GXStructureDataTypeInfo *sdtInfo;
@property(nonatomic, strong, readonly) GXStructureDataTypeBinaryDataLevelInfo *levelBinaryDataInfo;


@end



@interface GXStructureDataTypeBinaryDataInfoContainer : NSObject

- (instancetype)initWithSDTBinaryDataInfos:(nullable NSArray<GXStructureDataTypeBinaryDataInfo *> *)binaryDataInfos NS_DESIGNATED_INITIALIZER;

- (nullable GXStructureDataTypeBinaryDataInfo *)binaryDataInfoForSdtName:(NSString *)sdtBasedOnName;
- (void)enumerateSdtBinaryDataInfoWithBlock:(void(^)(GXStructureDataTypeBinaryDataInfo *sdtBinaryData, BOOL *stop))block;

- (BOOL)containsBinaryDataInfoForSdtName:(NSString *)sdtBasedOnName;
- (void)loadBinaryDataInfo:(nullable GXStructureDataTypeBinaryDataInfo *)sdtBinaryDataInfo forSdtName:(NSString *)sdtBasedOnName;

@end

NS_ASSUME_NONNULL_END
