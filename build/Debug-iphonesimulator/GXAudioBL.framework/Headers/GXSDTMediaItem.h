//
//  GXSDTMediaItem.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 6/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import GXObjectsModel;

@class GXSDTMediaItemProperties;

typedef NS_ENUM(NSUInteger, GXSDTMediaItemStreamType) {
	GXSDTMediaItemStreamTypeNone = 0,
	GXSDTMediaItemStreamTypeBuffered = 1,
	GXSDTMediaItemStreamTypeLive = 2
};

@interface GXSDTMediaItem : NSObject

@property (nonatomic, strong) NSString *mediaItemId;
@property (nonatomic, strong) NSString *mediaItemURI;
@property (nonatomic, strong) NSString *mediaItemTitle;
@property (nonatomic, strong) NSString *mediaItemSubtitle;
@property (nonatomic, strong) NSString *mediaItemDescription;
@property (nonatomic, strong) NSString *mediaItemImageString;
@property (nonatomic) NSInteger mediaItemDuration;
@property (nonatomic) BOOL mediaItemIsFavorite;
@property (nonatomic, strong) NSString *mediaItemContentType;
@property (nonatomic) GXSDTMediaItemStreamType mediaItemStreamType;

@property (nonatomic, strong) UIImage *mediaItemImage;

@property (nonatomic, strong) GXSDTMediaItemProperties *mediaItemMetadata;

- (instancetype)initWithSDTData:(id<GXSDTData>)sdtData;

- (void)downloadImageWithCompletionBlock:(void (^)(UIImage *))completionBlock;

- (NSDictionary<NSString *, id> *)dictionaryRepresentation;

@end
