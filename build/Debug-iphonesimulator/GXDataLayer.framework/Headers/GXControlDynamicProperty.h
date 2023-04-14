//
//  GXControlDynamicProperty.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 18/9/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GXControlDynamicPropertyType) {
	GXControlDynamicPropertyTypeProperty = 1,
	GXControlDynamicPropertyTypeMethod = 2
};

typedef NS_ENUM(NSInteger, GXControlDynamicPropertySource) {
	GXControlDynamicPropertySourceServer,
	GXControlDynamicPropertySourceClient
};

@interface GXControlDynamicPropertyBase: NSObject

@property(nonatomic, assign, readonly) GXControlDynamicPropertyType type;
@property(nonatomic, assign, readonly) GXControlDynamicPropertySource source;
@property(nonatomic, strong, readonly) NSString *controlLowercaseName;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithControlName:(NSString *)controlName; // source = Client
- (instancetype)initWithControlName:(NSString *)controlName
							 source:(GXControlDynamicPropertySource)source NS_DESIGNATED_INITIALIZER;

- (BOOL)isSameDynamicPropertyBase:(GXControlDynamicPropertyBase *)other;

@end

@interface GXControlDynamicProperty : GXControlDynamicPropertyBase

@property(nonatomic, strong, readonly) NSString *propertyLowercaseName;
@property(nonatomic, strong, readonly) id propertyValue; // NSNull if nullablePropertyValue is nil
@property(nullable, nonatomic, strong, readonly) id nullablePropertyValue;

- (instancetype)initWithControlName:(NSString *)controlName NS_UNAVAILABLE;
- (instancetype)initWithControlName:(NSString *)controlName source:(GXControlDynamicPropertySource)source NS_UNAVAILABLE;

- (instancetype)initWithControlName:(NSString *)controlName
					   propertyName:(NSString *)propertyName
					  propertyValue:(nullable id)propertyValue; // source = Client
- (instancetype)initWithControlName:(NSString *)controlName
					   propertyName:(NSString *)propertyName
					  propertyValue:(nullable id)propertyValue
							 source:(GXControlDynamicPropertySource)source NS_DESIGNATED_INITIALIZER;

@end

@interface GXControlDynamicMethod : GXControlDynamicPropertyBase

@property(nonatomic, strong, readonly) NSString *methodLowercaseName;
@property(nonatomic, strong, readonly) NSArray *parameters;

- (instancetype)initWithControlName:(NSString *)controlName NS_UNAVAILABLE;
- (instancetype)initWithControlName:(NSString *)controlName source:(GXControlDynamicPropertySource)source NS_UNAVAILABLE;

- (instancetype)initWithControlName:(NSString *)controlName
						 methodName:(NSString *)methodName
						 parameters:(nullable NSArray *)parameters; // source = Client
- (instancetype)initWithControlName:(NSString *)controlName
						 methodName:(NSString *)methodName
						 parameters:(nullable NSArray *)parameters
							 source:(GXControlDynamicPropertySource)source NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

