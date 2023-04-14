//
//  GXSharing.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 14/03/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, GXSharingType) {
	GXSharingActivity = 1 << 0,
	GXSharingEmail = 1 << 1,
	GXSharingSMS = 1 << 2,
	GXSharingTwitter = 1 << 3,
	GXSharingFacebook = 1 << 4,
};

#define kGXSharingType_All (GXSharingActivity | GXSharingEmail | GXSharingSMS | GXSharingTwitter | GXSharingFacebook)
#define kGXSharingType_AllButActivity (kGXSharingType_All ^ GXSharingActivity)

typedef void (^GXSharingCompletionHandler)(BOOL completed, NSError * _Nullable error, NSDictionary * _Nullable context);

@interface GXSharing : NSObject

@property (nonatomic, assign) GXSharingType sharingType;
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *toRecipients;
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *ccRecipients;
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *bccRecipients;
@property (nullable, nonatomic, strong)  NSString *text;
@property (nullable, nonatomic, strong)  NSString *subject;

/**
 * Indicates if the device can share with any of the supported types
 */
+ (BOOL)canShare;

/**
 * Indicates if the devices can share with any of the types that support images
 */
+ (BOOL)canShareWithImage;

/**
 * Indicates if the devices can share with any of the given types
 * To specify more than one type, use the bitwise | operator:
 *   BOOL canShare = [GXSharing canShareWithTypes:(GXSharingTwitter | GXSharingFacebook)];
 */
+ (BOOL)canShareWithTypes:(GXSharingType)types;

/**
 * Adds a new image to share (if supported by the selected sharing type)
 */
- (void)addImage:(UIImage *)image withURLString:(nullable NSString *)urlStr;

/**
 * Add a new "to" recipient to the list (if supported)
 */
- (void)addToRecipient:(nullable NSString *)to;
- (void)addToRecipients:(nullable NSArray<NSString *> *)to;

/**
 * Add a new "cc" recipient to the list (if supported)
 */
- (void)addCcRecipient:(nullable NSString *)cc;
- (void)addCcRecipients:(nullable NSArray<NSString *> *)cc;

/**
 * Add a new "bcc" recipient to the list (if supported)
 */
- (void)addBccRecipient:(nullable NSString *)bcc;
- (void)addBccRecipients:(nullable NSArray<NSString *> *)bcc;

/**
 * Adds file attachment to share if supported, given by the file's path
 */
- (void)addFileAttachment:(NSString *)filePath;

/**
 * Adds file attachments to share if supported, given by the files' path
 */
- (void)addFileAttachments:(NSArray<NSString *> *)filePaths;

/*!
 Performs the sharing action
 
 @param uiContext User interface context to present share user interface.
 @param completionHandler Completion handler block (Optional).
 @result Returns <tt>YES</tt> if share user interface could be presented, <tt>NO</tt> otherwise.
 @discussion Note that completionHandler will be called only if this method returns <tt>YES</tt>.
 */
- (BOOL)shareFromUserInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
                    completionHandler:(GXSharingCompletionHandler)completionHandler;

@end

@interface GXSharing (Helpers)

#if TARGET_OS_IOS
+ (void)tryUpdateActivityItems:(NSMutableArray *)activityItems withTitle:(nullable NSString *)title;
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
