//
//  GXDataLayer.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 18/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
//! Project version number for GXDataLayer.
FOUNDATION_EXPORT double GXDataLayerVersionNumber;

//! Project version string for GXDataLayer.
FOUNDATION_EXPORT const unsigned char GXDataLayerVersionString[];

#import <GXDataLayer/GXBaseDetailEntityDataProvider.h>
#import <GXDataLayer/GXBaseEntityDataProvider.h>
#import <GXDataLayer/GXBaseListEntityDataProvider.h>
#import <GXDataLayer/GXBinaryDataFieldReference.h>
#import <GXDataLayer/GXBusinessComponentDefaultLoadHandler.h>
#import <GXDataLayer/GXBusinessComponentDeleteHandler.h>
#import <GXDataLayer/GXBusinessComponentHandler.h>
#import <GXDataLayer/GXBusinessComponentHandlerBuilderProtocol.h>
#import <GXDataLayer/GXBusinessComponentInsertHandlerProtocol.h>
#import <GXDataLayer/GXBusinessComponentLoadHandler.h>
#import <GXDataLayer/GXBusinessComponentManager.h>
#import <GXDataLayer/GXBusinessComponentSaveHandler.h>
#import <GXDataLayer/GXBusinessComponentUpdateHandlerProtocol.h>
#import <GXDataLayer/GXBusinessComponentWithKeyHandler.h>
#import <GXDataLayer/GXCompositeEntityData.h>
#import <GXDataLayer/GXControlDynamicProperty.h>
#import <GXDataLayer/GXDataLayerServices.h>
#import <GXDataLayer/GXDynamicCallHelper.h>
#import <GXDataLayer/GXDynamicPropertiesCollection.h>
#import <GXDataLayer/GXEntityDataDescriptorDictionary.h>
#import <GXDataLayer/GXEntityDataDetailProviderProtocol.h>
#import <GXDataLayer/GXEntityDataEmpty.h>
#import <GXDataLayer/GXEntityDataFieldDynamicComboData.h>
#import <GXDataLayer/GXEntityDataFieldDynamicComboProvider.h>
#import <GXDataLayer/GXEntityDataFieldHideCodeProvider.h>
#import <GXDataLayer/GXEntityDataKey.h>
#import <GXDataLayer/GXEntityDataKeyDescriptor.h>
#import <GXDataLayer/GXEntityDataListAdvancedFilterProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListBreakByProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListOrderProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListSearchProviderProtocol.h>
#import <GXDataLayer/GXEntityDataManager.h>
#import <GXDataLayer/GXEntityDataManagerInternalBaseOperation.h>
#import <GXDataLayer/GXEntityDataManagerLoaderInternalContext.h>
#import <GXDataLayer/GXEntityDataProviderHelper.h>
#import <GXDataLayer/GXEntityDataProviderProtocol.h>
#import <GXDataLayer/GXEntityDataQueryInfo.h>
#import <GXDataLayer/GXEntityDataQueryInfoProtocol.h>
#import <GXDataLayer/GXEntityDataQueryResult.h>
#import <GXDataLayer/GXEntityDataQueryResultProtocol.h>
#import <GXDataLayer/GXEntityDataWithDictionary.h>
#import <GXDataLayer/GXEntityDataWithFieldResolver.h>
#import <GXDataLayer/GXEntityDataWithNameMappings.h>
#import <GXDataLayer/GXEntityDataWithOverrideValues.h>
#import <GXDataLayer/GXEntityDataWrapper.h>
#import <GXDataLayer/GXEntityHelper+GXActionParameters.h>
#import <GXDataLayer/GXEntityHelper+GXBinaryDataFieldReference.h>
#import <GXDataLayer/GXEntityHelper+GXCoreDataFieldValueConversion.h>
#import <GXDataLayer/GXEntityHelper+GXDataLayer_EntityDataDescriptor.h>
#import <GXDataLayer/GXEntityHelper+GXDisplayStringFieldValueConversion.h>
#import <GXDataLayer/GXEntityHelper+GXDynamicProperties.h>
#import <GXDataLayer/GXEntityHelper+GXEntityData.h>
#import <GXDataLayer/GXEntityHelper+GXFieldSpecifier.h>
#import <GXDataLayer/GXEntityHelper+GXFieldValueConversion.h>
#import <GXDataLayer/GXEntityHelper+GXJsonBusinessComponentValueConversion.h>
#import <GXDataLayer/GXEntityHelper+GXJsonFieldValueConversion.h>
#import <GXDataLayer/GXEntityHelper+GXURLParameters.h>
#import <GXDataLayer/GXEntityHelper+GXWebFieldValueConversion.h>
#import <GXDataLayer/GXEntityHelper+GXWebImageManager.h>
#import <GXDataLayer/GXEntityRulePromptAfterServiceProvider.h>
#import <GXDataLayer/GXFieldComparator.h>
#import <GXDataLayer/GXImageCache.h>
#import <GXDataLayer/GXImageUploadHelper.h>
#import <GXDataLayer/GXImage+GXWebImage.h>
#import <GXDataLayer/GXLocalEntityDataQueryInfoProtocol.h>
#import <GXDataLayer/GXMutableEntityDataDetailProviderProtocol.h>
#import <GXDataLayer/GXObjectUploaderService.h>
#import <GXDataLayer/GXRemoteEntityDataListProviderProtocol.h>
#import <GXDataLayer/GXRemoteEntityDataListSearchProviderProtocol.h>
#import <GXDataLayer/GXRemoteEntityDataProviderProtocol.h>
#import <GXDataLayer/GXRemoteEntityDataQueryInfoProtocol.h>
#import <GXDataLayer/GXRemoteEntityDataQueryResultProtocol.h>
#import <GXDataLayer/GXRemoteMutableEntityDataDetailProviderProtocol.h>
#import <GXDataLayer/GXSDTData.h>
#import <GXDataLayer/GXSDTMessagesHelper.h>
#import <GXDataLayer/GXSynchronizationBlobDownloadService.h>
#import <GXDataLayer/GXSynchronizationReceiveService.h>
#import <GXDataLayer/GXSynchronizationSendEventProtocol.h>
#import <GXDataLayer/GXSynchronizationSendService.h>
#import <GXDataLayer/GXStructureDataTypeBinaryDataInfo.h>
#import <GXDataLayer/GXStructureDataTypeBinaryDataLevelMemberInfo.h>
#import <GXDataLayer/GXWebImageCompat.h>
#import <GXDataLayer/GXWebImageCustomURLSchemeManager.h>
#import <GXDataLayer/GXWebImageDecoder.h>
#import <GXDataLayer/GXWebImageDefine.h>
#import <GXDataLayer/GXWebImageDownloader.h>
#import <GXDataLayer/GXWebImageDownloaderBaseOperation.h>
#import <GXDataLayer/GXWebImageDownloaderOperation.h>
#import <GXDataLayer/GXWebImageHelper.h>
#import <GXDataLayer/GXWebImageManager.h>
#import <GXDataLayer/GXWebImageOperation.h>
#import <GXDataLayer/GXWebImagePrefetcher.h>
#import <GXDataLayer/GXWorkWithDataSource.h>
#import <GXDataLayer/GXWorkWithEntityDataProviderHelper.h>
#import <GXDataLayer/GXWorkWithDetailEntityDataProviderHelper.h>
#import <GXDataLayer/GXWorkWithSectionEntityDataProviderHelper.h>

#import <GXDataLayer/NSIndexPath+GXEntityDataListProvider.h>
