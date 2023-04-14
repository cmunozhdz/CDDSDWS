//
//  GXUUID+GXStd.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 7/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXUUID (GXStd)

- (NSString *)toString;

/*
 * Compares the current GXUUID with the given object.
 *
 * @param obj The object to perform the comparision with, may be a NSString or a GXUUID
 */
- (NSComparisonResult)compare:(id)obj;

- (NSNumber *)gxIsEmpty;

@end

NS_ASSUME_NONNULL_END
