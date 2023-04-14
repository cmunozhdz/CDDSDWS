//
//  GXConstants.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

#define kGXObjectIdLength 36
#define kGXObjectIdSeparatorLength 1
#define kGXObjectIdWithSeparatorLength kGXObjectIdLength + kGXObjectIdSeparatorLength

#define kGXObjectIdSeparator @"-"

#define kGXObjectIdImage				@"9fb193d9-64a4-4d30-b129-ff7c76830f7e"
#define kGXObjectIdDashboard			@"9bdcc055-174e-4af6-96cb-a2ceef6c5f09"
#define kGXObjectIdSdPanel              @"d82625fd-5892-40b0-99c9-5c8559c197fc"
#define kGXObjectIdWorkWith				@"15cf49b5-fc38-4899-91b5-395d02d79889"
#define kGXObjectIdBusinessComponent	@"1db606f2-af09-4cf9-a3b5-b481519d28f6"
#define kGXObjectIdAttribute			@"adbb33c9-0906-4971-833c-998de27e0676"
#define kGXObjectIdDomain				@"00972a17-9975-449e-aab1-d26165d51393"
#define kGXObjectIdProcedure			@"84a12160-f59b-4ad7-a683-ea4481ac23e9"
#define kGXObjectIdExternalObject		@"c163e562-42c6-4158-ad83-5b21a14cf30e"
#define kGXObjectIdTheme				@"c804fdbd-7c0b-440d-8527-4316c92649a6"
#define kGXObjectIdDesignSystem			@"78b3fa0e-174c-4b2b-8716-718167a428b5"
#define kGXObjectIdSDT                  @"447527b5-9210-4523-898b-5dccb17be60a"
#define kGXObjectIdWebPanel             @"c9584656-94b6-4ccd-890f-332d11fc2c25"
#define kGXObjectIdDataProvider			@"2a9e9aba-d2de-4801-ae7f-5e3819222daf"
#define kGXObjectIdQuery				@"926a06b9-3417-4ab4-9f8c-09c2f626bb1c"
#define kGXObjectIdFile					@"1132ac08-290f-4fd1-bd18-64777b7329d1"
#define kGXEmptyGuid					@"00000000-0000-0000-0000-000000000000"

typedef NS_ENUM(uint_least8_t, GXObjectType) {
	GXObjectTypeUnknown,
	GXObjectTypeImage,
	GXObjectTypeDashboard,
	GXObjectTypeSdPanel,
	GXObjectTypeWorkWith,
	GXObjectTypeBusinessComponent,
	GXObjectTypeAttribute,
	GXObjectTypeDomain,
	GXObjectTypeProcedure,
	GXObjectTypeExternalObject,
	GXObjectTypeTheme,
	GXObjectTypeSDT,
	GXObjectTypeWebPanel,
	GXObjectTypeDataProvider,
	GXObjectTypeQuery,
	GXObjectTypeDesignSystem,
	GXObjectTypeFile,
};
