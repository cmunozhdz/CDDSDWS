//
//  GXSDTMessagesHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 14/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXSDTMessagesHelper : NSObject

+ (id<GXSDTData>)errorSDTMessageWithId:(NSString *)idStr description:(NSString *)descr;

+ (id<GXSDTData>)sdtDataFromJSONErrorSDTMessageWithDescription:(NSString *)descr;

@end

NS_ASSUME_NONNULL_END
