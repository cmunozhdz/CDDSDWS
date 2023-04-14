//
//  GXKeyChainStore.h
//  GXFlexibleClient
//
//	The MIT License
//
//	Copyright (c) 2011 Kishikawa Katsumi
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  Modified by Fabian Inthamoussu on 27/08/12.
//

@import Foundation;
@import Security;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXKeyChainStoreErrorDomain;

@interface GXKeyChainStore : NSObject

@property(nonatomic, strong, readonly) NSString *service;
@property(nullable, nonatomic, strong, readonly) NSString *accessGroup;

+ (NSString *)defaultService;
#if TARGET_IPHONE_SIMULATOR
+ (NSString *)privateAccessGroup __deprecated_msg("privateAccessGroup is not supported in the simulator, use simulatorPrivateAccessGroupKeyFor: instead for simulator");
#else
+ (NSString *)privateAccessGroup;
#endif

+ (NSString *)sharedAccessGroup;

#if TARGET_IPHONE_SIMULATOR

// Ignore the access group if running on the iPhone simulator.
//
// Apps that are built for the simulator aren't signed, so there's no keychain access group
// for the simulator to check. This means that all apps can see all keychain items when run
// on the simulator.
//
// If a SecItem contains an access group attribute, SecItemAdd and SecItemUpdate on the
// simulator will return -25243 (errSecNoAccessForItem).
// Simulate it with appending a suffix to the key

+ (NSString *)simulatorPrivateAccessGroupKeyFor:(NSString *)key;
+ (BOOL)isSimulatorPrivateAccessGroupKey:(NSString *)key;

#endif

+ (nullable NSString *)stringForKey:(NSString *)key;
+ (nullable NSString *)stringForKey:(NSString *)key service:(nullable NSString *)service;
+ (nullable NSString *)stringForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (nullable NSString *)stringForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup attributes:(nullable NSDictionary<NSString *, id> *)attributes error:(NSError * __autoreleasing _Nullable * _Nullable)error __attribute__((swift_error(nonnull_error)));
+ (nullable NSError *)setString:(nullable NSString *)value forKey:(NSString *)key;
+ (nullable NSError *)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service;
+ (nullable NSError *)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (nullable NSError *)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup attributes:(nullable NSDictionary<NSString *, id> *)attributes;

+ (nullable NSData *)dataForKey:(NSString *)key;
+ (nullable NSData *)dataForKey:(NSString *)key service:(nullable NSString *)service;
+ (nullable NSData *)dataForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (nullable NSData *)dataForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup attributes:(nullable NSDictionary<NSString *, id> *)attributes error:(NSError * __autoreleasing _Nullable * _Nullable)error __attribute__((swift_error(nonnull_error)));
+ (nullable NSError *)setData:(nullable NSData *)data forKey:(NSString *)key;
+ (nullable NSError *)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service;
+ (nullable NSError *)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (nullable NSError *)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup attributes:(nullable NSDictionary<NSString *, id> *)attributes;

+ (nullable NSError *)removeItemForKey:(NSString *)key;
+ (nullable NSError *)removeItemForKey:(NSString *)key service:(nullable NSString *)service;
+ (nullable NSError *)removeItemForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (nullable NSError *)removeAllItems;
+ (nullable NSError *)removeAllItemsForService:(nullable NSString *)service;
+ (nullable NSError *)removeAllItemsForService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (nullable NSError *)removeAllItemsWithKeysMatching:(BOOL(^ _Nullable)(NSString *))keyMatchingBlock forService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

+ (GXKeyChainStore *)keyChainStore;
+ (GXKeyChainStore *)keyChainStoreWithService:(nullable NSString *)service;
+ (GXKeyChainStore *)keyChainStoreWithService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

- (instancetype)init;
- (instancetype)initWithService:(nullable NSString *)service;
- (instancetype)initWithService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup NS_DESIGNATED_INITIALIZER;

- (void)setString:(nullable NSString *)string forKey:(NSString *)key;
- (nullable NSString *)stringForKey:(NSString *)key;

- (void)setData:(nullable NSData *)data forKey:(NSString *)key;
- (nullable NSData *)dataForKey:(NSString *)key;

- (void)removeItemForKey:(NSString *)key;
- (void)removeAllItems;

- (void)synchronize;

@end

NS_ASSUME_NONNULL_END
