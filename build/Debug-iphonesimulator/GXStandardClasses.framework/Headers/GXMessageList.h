//
//  GXMsgList.h
//  GXStd
//
//  Created by Alejandro Panizza on 9/17/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXStandardClasses/GXObjectCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXMessageList : GXObjectCollection

- (BOOL)hasErrorItems;

/*!
 Receives an array with the message information to be added to the collection
 
 @param arguments The array with the message information. The first item is the description, follwed by the id and finally the type
 @discussion If the array has more than three items, the elements after the third are ignored. If it has less than three, default values are used
 */
- (void)addElement:(nullable NSArray *)arguments;

- (NSString *)firstErrorMessage;

@end

NS_ASSUME_NONNULL_END
