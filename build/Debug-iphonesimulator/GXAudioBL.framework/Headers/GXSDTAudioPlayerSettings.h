//
//  GXSDTAudioPlayerSettings.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 8/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXAudioBL/GXSDTAudioPlayerCustomAction.h>

@interface GXSDTAudioPlayerSettings : NSObject

@property (nonatomic) BOOL supportsFavorite;
@property (nonatomic) BOOL supportsRepeat;
@property (nonatomic) BOOL supportsShuffle;
@property (nonatomic, strong) NSArray<GXSDTAudioPlayerCustomAction *> *customActions;

- (instancetype)initWithSDTData:(id<GXSDTData>)sdtData;

- (NSDictionary *)dictionaryRepresentation;

@end
