//
//  GXObjectUploaderService.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 7/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXBinaryDataFieldReference.h>

@protocol GXObjectUploader;

NS_ASSUME_NONNULL_BEGIN

@protocol GXObjectUploaderService <NSObject>

- (NSOperation<GXObjectUploader> *)objectUploaderOperationWithBinaryDataFieldReferences:(NSArray<GXBinaryDataFieldReference *> *)binaryDataFieldReferences
																		 forModelObject:(id<GXModelObject>)modelObject;

@end

@protocol GXObjectUploaderDelegate <NSObject>

- (nullable NSString *)objectUploaderRestPath:(id<GXObjectUploader>)uploader;

@optional
- (void)objectUploaderDidFinishUploading:(id<GXObjectUploader>)uploader;
- (void)objectUploader:(id<GXObjectUploader>)uploader didFailUploadingWithError:(NSError *)error;

@end

@protocol GXObjectUploader <NSObject>

// Input Data
@property(nullable, weak, readonly) GXModel *gxModel;
@property(nonatomic, strong, readonly) NSArray<GXBinaryDataFieldReference *> *binaryDataFieldReferences;
// Output Data
@property(nullable, nonatomic, strong, readonly) NSError *error;
// Delegate
@property(nullable, nonatomic, weak) id <GXObjectUploaderDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
