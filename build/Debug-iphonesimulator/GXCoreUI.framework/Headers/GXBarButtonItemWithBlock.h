//
//  GXBarButtonItemWithBlock.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 05/09/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import UIKit;

typedef void (^GXBarButtonItemWithBlockActionHanlder)(void);

@interface GXBarButtonItemWithBlock : UIBarButtonItem

@property(nullable, copy) GXBarButtonItemWithBlockActionHanlder actionHandlerBlock;

@end
