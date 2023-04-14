//
//  GXProcedure.h
//  GXStandardClasses
//
//  Created by Fabian Inthamoussu on 8/3/22.
//  Copyright © 2022 GeneXus. All rights reserved.
//

#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXProcedure : GXEmbeddedModelNSObject

@property (nonatomic, strong) NSString *Gx_mode NS_SWIFT_NAME(Gx_mode);

#pragma mark - Abstract methods (implementend by generated subclasses)

- (void)setCreateDataBase;
- (void)cleanup;
- (void)initialize;

@end

NS_ASSUME_NONNULL_END
