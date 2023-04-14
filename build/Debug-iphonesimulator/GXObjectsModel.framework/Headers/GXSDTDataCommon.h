//
//  GXSDTDataCommon.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/03/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;

#define GXSDT_CollectionItemFormat @"Item(%ld)"
#define GXSDT_CollectionCurrentItem @"CurrentItem"
#define GXSDT_CollectionLowercaseCurrentItem @"currentitem"
#define GXSDT_CollectionItem @"Item"
#define GXSDT_CollectionLowercaseItem @"item"
#define GXSDT_CollectionItem0 @"Item(0)"
#define GXSDT_CollectionItemOpenBracket @"("
#define GXSDT_CollectionItemCloseBracket @")"
#define GXSDT_CollectionCount @"Count"
#define GXSDT_CollectionLowercaseCount @"count"
#define GXSDT_MemberSeparator @"."

static inline NSString * GXSDT_CollectionItemAtIndex(long itemIndex)
{
	return [NSString stringWithFormat:GXSDT_CollectionItemFormat, itemIndex];
}

#define GXSDT_CollectionItemAtIndexWithLiteralStringMember(itemIndex, LITERAL_STR_MEMBER) [NSString stringWithFormat:GXSDT_CollectionItemFormat GXSDT_MemberSeparator LITERAL_STR_MEMBER, itemIndex]