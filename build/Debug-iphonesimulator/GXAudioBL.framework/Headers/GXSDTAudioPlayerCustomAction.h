//
//  GXSDTAudioPlayerCustomAction.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 11/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;

@interface GXSDTAudioPlayerCustomAction : NSObject

@property (nonatomic, strong) NSString *customActionId;
@property (nonatomic, strong) NSString *customActionTitle;
@property (nonatomic, strong) NSString *customActionImage;

- (instancetype)initWithSDTData:(id<GXSDTData>)sdtData;

- (NSDictionary *)dictionaryRepresentation;

@end
