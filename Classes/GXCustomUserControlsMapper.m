//
//  GXCustomUserControlsMapper.m
//  CDDSD
//

#import "GXCustomUserControlsMapper.h"

@implementation GXCustomUserControlsMapper

- (nullable NSString *)userControlClassNameForControlName:(NSString *)name {
	if ([name isEqualToString:@"SDPlusProgressBar"])
		return @"SDPlusProgressBar";

	return nil;
}

@end
