//
//  GXEnumeration.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 3/20/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXStandardClasses/GXObjectCollection.h>
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEnumeration : GXEmbeddedModelNSObject {
    NSDictionary *_dictionary;
}

- (NSString *)getDescriptionKey:(id)key;

- (GXObjectCollection *)getValues;

@end

NS_ASSUME_NONNULL_END
