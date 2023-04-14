//
//  GXAnalyticsService.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@protocol GXAnalyticsServiceSender

@optional
@property(nullable, nonatomic, strong, readonly) NSString *gxAnalyticsServiceSenderLabel;
@property(nullable, nonatomic, strong, readonly) NSNumber *gxAnalyticsServiceSenderValue;

@end

@protocol GXAnalyticsService <NSObject>

- (void)trackView:(NSString *)viewName;
- (void)trackViewFromObject:(id<GXSDObjectLocator>)object NS_SWIFT_NAME(trackView(from:));

- (void)trackEventName:(NSString *)name category:(NSString *)category label:(nullable NSString *)label value:(nullable NSNumber *)value;
- (void)trackEventName:(NSString *)name from:(id<GXSDObjectLocator>)object sender:(nullable id)sender;

- (void)setUserId:(NSString *)userId;
- (void)setCommerceTrackerId:(NSString *)trackerId;

- (void)trackPurchaseId:(NSString *)purchaseId
			affiliation:(NSString *)affiliation
				revenue:(NSNumber *)revenue
					tax:(NSNumber *)tax
			   shipping:(NSNumber *)shipping
		   currencyCode:(NSString *)currencyCode;

- (void)trackPurchasedItem:(NSString *)productId
				purchaseId:(NSString *)purchaseId
					  name:(NSString *)name
				  category:(NSString *)category
					 price:(NSNumber *)price
				  quantity:(NSNumber *)quantity
			  currencyCode:(NSString *)currencyCode;

@end

NS_ASSUME_NONNULL_END
