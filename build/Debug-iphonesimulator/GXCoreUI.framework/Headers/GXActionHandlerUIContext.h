//
//  GXActionHandlerUIContext.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 3/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
@import GXCoreBL;

NS_ASSUME_NONNULL_BEGIN

@interface GXActionHandlerUIContext : GXActionHandlerContext <GXActionHandlerUIContext>
@end


@interface GXActionHandlerUIContextWrapper : GXActionHandlerContextWrapper <GXActionHandlerUIContext>
@end

NS_ASSUME_NONNULL_END
