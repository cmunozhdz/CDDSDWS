//
//  GXCommonTypes.h
//  GXObjectsModel
//
//  Created by Marcos Crispino on 6/16/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

#if !TARGET_OS_WATCH
typedef UIViewController GXUserInterfaceController;
#else
typedef WKInterfaceController GXUserInterfaceController;
#endif

