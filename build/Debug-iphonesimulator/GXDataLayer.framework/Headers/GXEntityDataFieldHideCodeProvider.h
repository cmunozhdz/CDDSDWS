//
//  GXEntityDataFieldHideCodeProvider.h
//  GXFlexibleClient
//
//  Created by willy on 4/30/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

typedef NS_ENUM(uint_least8_t, GXHideCodeErrorCode) {
	GXHideCodeErrorCode_OK,
	GXHideCodeErrorCode_NOT_FOUND,
	GXHideCodeErrorCode_AMBIGUOUS_CK
};

typedef NS_ENUM(uint_least8_t, GXHideCodeServiceType) {
	GXHideCodeServiceType_None,
	GXHideCodeServiceTypeHC,
	GXHideCodeServiceTypeHC_REV,
	GXHideCodeServiceTypeSG
};

@class GXEntityDataFieldHideCodeProvider;

@protocol GXEntityDataFieldHideCodeProviderDelegate <NSObject>

- (void)entityDataFieldHideCodeProvider:(GXEntityDataFieldHideCodeProvider *)provider
						didLoadHideCode:(id)hideCode
						  withErrorCode:(GXHideCodeErrorCode)errorCode;

- (void)entityDataFieldHideCodeProvider:(GXEntityDataFieldHideCodeProvider *)provider
					 didLoadDescription:(NSString *)description;

- (void)entityDataFieldHideCodeProvider:(GXEntityDataFieldHideCodeProvider *)provider
					didLoadSuggestItems:(NSArray *)items;

- (void)entityDataFieldHideCodeProvider:(GXEntityDataFieldHideCodeProvider *)provider
				didFailLoadingWithError:(NSError *)error;

@end

@interface GXEntityDataFieldHideCodeProvider : NSObject

+ (GXEntityDataFieldHideCodeProvider *)hideCodeProviderWithEntityData:(id<GXEntityData>)entityData
													  fieldDescriptor:(id <GXEntityDataFieldDescriptor>)fieldDescriptor
													  hideCodeService:(id<GXDynamicDataService>)hideCodeService
													   suggestService:(id<GXDynamicDataService>)suggestService
												   hideCodeRevService:(id<GXDynamicDataService>)hideCodeRevService
												  connectivitySupport:(GXConnectivitySupportType)connSupport;

@property (nonatomic, strong, readonly) id<GXDynamicDataService> serviceHideCode;
@property (nonatomic, strong, readonly) id<GXDynamicDataService> serviceHideCodeRev;
@property (nonatomic, strong, readonly) id<GXDynamicDataService> serviceSuggest;
@property (nonatomic, strong) id<GXEntityData> entityData;
@property (nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport;
@property (nonatomic, weak) id<GXEntityDataFieldHideCodeProviderDelegate> delegate;
@property (nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> fieldDescriptor;

- (void)loadSuggestWithText:(NSString *)text;
- (void)loadHideCodeForText:(NSString *)text;
- (void)loadTextForHideCode;
- (void)cancel;

@end
