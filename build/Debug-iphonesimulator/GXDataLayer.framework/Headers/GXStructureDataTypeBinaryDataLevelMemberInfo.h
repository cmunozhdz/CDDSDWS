//
//  GXStructureDataTypeBinaryDataLevelMemberInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/05/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXStructureDataTypeBinaryDataItemInfoType) {
	GXStructureDataTypeBinaryDataItemInfoTypeItem,
	GXStructureDataTypeBinaryDataItemInfoTypeLevel
};


@interface GXStructureDataTypeBinaryDataLevelMemberInfo : NSObject // Abstract

@property(nonatomic, assign, readonly) GXStructureDataTypeBinaryDataItemInfoType type;

@end


@interface GXStructureDataTypeBinaryDataItemInfo : GXStructureDataTypeBinaryDataLevelMemberInfo

- (instancetype)initWithItemInfo:(GXStructureDataTypeItemInfo *)sdtLevelInfo NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) GXStructureDataTypeItemInfo *sdtItemInfo;

@end


@interface GXStructureDataTypeBinaryDataLevelInfo : GXStructureDataTypeBinaryDataLevelMemberInfo

- (instancetype)initWithLevelInfo:(GXStructureDataTypeLevelInfo *)sdtLevelInfo
					 isCollection:(BOOL)isCollection
	   childBinaryDataMembersInfo:(nullable NSArray<__kindof GXStructureDataTypeBinaryDataLevelMemberInfo *> *)childMembers NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithLevelInfo:(GXStructureDataTypeLevelInfo *)sdtLevelInfo
	   childBinaryDataMembersInfo:(nullable NSArray<__kindof GXStructureDataTypeBinaryDataLevelMemberInfo *> *)childMembers;
- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, readonly) BOOL isCollection; // May be different than sdtLevelInfo.isCollection. I.e. sdtLevelInfo.isCollection == YES but self.isCollection == NO refers to level collection items
@property(nonatomic, strong, readonly) GXStructureDataTypeLevelInfo *sdtLevelInfo;
@property(nonatomic, strong, readonly) NSArray<__kindof GXStructureDataTypeBinaryDataLevelMemberInfo *> *childBinaryDataMembersInfo;

- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;

@end

NS_ASSUME_NONNULL_END
