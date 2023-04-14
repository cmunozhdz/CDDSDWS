//
//  GXProcedureModel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 08/03/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXNamedModelObjectChild.h>
#import <GXObjectsModel/GXProcedureParameter.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXProcedureModelType) {
	GXProcedureModelTypeProcedure,
	GXProcedureModelTypeDataprovider
};

@interface GXProcedureModel : GXNamedModelObjectChild {
	NSArray<GXProcedureParameter *> *_parameters;
}

@property(nonnull, nonatomic, strong, readonly) NSString *name;
@property(nullable, nonatomic, strong, readonly) NSArray<GXProcedureParameter *> *parameters;
@property(nonatomic, assign, readonly) GXProcedureModelType procType;
@property(nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport;

+ (nullable instancetype)procedureModelFromMetadata:(NSDictionary<NSString *, id> *)metadata
									 forModelObject:(nullable id<GXModelObject>)modelObject
											  error:(NSError * __autoreleasing *)error;

- (instancetype)initWithName:(NSString *)name
						type:(GXProcedureModelType)type
				  parameters:(nullable NSArray<GXProcedureParameter *> *)params
		 connectivitySupport:(GXConnectivitySupportType)connSupport
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
