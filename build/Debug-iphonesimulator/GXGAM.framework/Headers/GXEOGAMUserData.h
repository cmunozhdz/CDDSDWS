//
//  GXEOGAMUserData.h
//  GXFlexibleClient
//
//  Created by Alejandro Panizza on 16/08/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXCoreBL;
@import GXStandardClasses;

@interface GXEOGAMUserData : GXExternalObjectBase

@property (nonatomic,  strong )  NSString * GUID NS_SWIFT_NAME(GUID);
@property (nonatomic,  strong )  NSString * nameSpace ;
@property (nonatomic,  strong )  NSString * authenticationtypename ;
@property (nonatomic,  strong )  NSString * name ;
@property (nonatomic,  strong )  NSString * login ;
@property (nonatomic,  strong )  NSString * email ;
@property (nonatomic,  strong )  NSString * externalid ;
@property (nonatomic,  strong )  NSString * firstname ;
@property (nonatomic,  strong )  NSString * lastname ;
@property (nonatomic,  strong )  NSDate   * birthday ;
@property (nonatomic,  strong )  NSString * gender ;
@property (nonatomic,  strong )  NSString * urlimage ;
@property (nonatomic,  strong )  NSString * urlprofile ;
@property (nonatomic,  strong )  NSString * phone ;
@property (nonatomic,  strong )  NSString * address ;
@property (nonatomic,  strong )  NSString * address2 ;
@property (nonatomic,  strong )  NSString * city ;
@property (nonatomic,  strong )  NSString * state ;

@property (nonatomic,  strong )  NSString * postcode ;
@property (nonatomic,  strong )  NSString * language ;
@property (nonatomic,  strong )  NSString * timezone ;
@property (nonatomic,  assign )  BOOL isautoregistereduser ;

- (GXEOGAMUserData *)get;

- (NSString *)getemail;

- (NSString *)getlogin;

- (NSString *)getname;

- (NSString *)getlastname;

- (NSString *)getfirstname;

- (NSString *)getexternalid;

- (NSString *)getid;

- (BOOL)isanonymous;

@property (nonatomic, assign) BOOL cannotchangepassword;
@property (nonatomic, assign) BOOL dontreceiveinformation;
@property (nonatomic, assign) BOOL isactive;
@property (nonatomic, assign) BOOL isblocked;
@property (nonatomic, assign) BOOL isdeleted;
@property (nonatomic, assign) BOOL isenabledinrepository;
@property (nonatomic, assign) BOOL mustchangepassword;
@property (nonatomic, assign) BOOL passwordneverexpires;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *usercreated;
@property (nonatomic, strong) NSString *userupdated;
@property (nonatomic, strong) NSDate *activationdate;
@property (nonatomic, strong) NSDate *datecreated;
@property (nonatomic, strong) NSDate *datelastauthentication;
@property (nonatomic, strong) NSDate *datelastchangepassword;
@property (nonatomic, strong) NSDate *dateupdated;
@property (nonatomic, strong) NSDate *lastblockeddate;
@property (nonatomic, assign) NSInteger securitypolicyid;
@property (nonatomic, assign) long long defaultroleid;

@end
