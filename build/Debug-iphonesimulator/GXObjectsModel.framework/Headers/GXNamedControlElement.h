//
//  GXNamedControlElement.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXNamedControlElement <NSObject>

@property(nonatomic, strong, readonly) NSString *controlName;

@end

NS_ASSUME_NONNULL_END
