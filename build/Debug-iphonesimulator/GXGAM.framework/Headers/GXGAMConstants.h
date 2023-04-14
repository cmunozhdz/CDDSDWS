//
//  GXGAMConstants.h
//  GXGAM
//
//  Created by Marcos Crispino on 7/16/19.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

#pragma mark - GAM Module names

#define kGXGAM_Module_Name @"GeneXusSecurity"

#define kGXGAM_GAMUserEO_Name @"GAMUser"
#define kGXGAM_GAMApplicationEO_Name @"GAMApplication"
#define kGXGAM_GAMLoginEventsEO_Name @"GAMLoginEvents"

#define kGXGAM_Module_GAMUserEO_FullName        kGXGAM_Module_Name kGXModule_Separator kGXGAM_GAMUserEO_Name
#define kGXGAM_Module_GAMApplicationEO_FullName kGXGAM_Module_Name kGXModule_Separator kGXGAM_GAMApplicationEO_Name
#define kGXGAM_Module_GAMLoginEventsEO_FullName kGXGAM_Module_Name kGXModule_Separator kGXGAM_GAMLoginEventsEO_Name

#pragma mark - GAM event names

#define kGXGAMLoginEventsEO_TwoFactorAuthenticationRequested_EventName	kGXGAM_Module_GAMLoginEventsEO_FullName kGXModule_Separator @"TwoFactorAuthenticationRequested"
#define kGXGAMLoginEventsEO_OTPAuthenticationRequested_EventName	kGXGAM_Module_GAMLoginEventsEO_FullName kGXModule_Separator @"OTPAuthenticationRequested"
