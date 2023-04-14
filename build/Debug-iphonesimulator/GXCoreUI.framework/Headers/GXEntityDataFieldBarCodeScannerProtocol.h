//
//  GXEntityDataFieldBarCodeScannerProtocol.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 11/14/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import UIKit;
#import <GXCoreUI/GXEntityDataFieldViewControllerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataFieldBarCodeScanner;

@protocol GXEntityDataFieldBarCodeScannerDelegate <GXEntityDataFieldEditorViewControllerDelegate>

- (void)entityDataFieldBarCodeScanner:(UIViewController<GXEntityDataFieldBarCodeScanner> *)scanner
                       didReadBarCode:(NSString *)barcode;

@end

@protocol GXEntityDataFieldBarCodeScanner <GXEntityDataFieldEditorViewController>

@property(nonatomic, assign) BOOL scanInLoop;
@property(nonatomic, assign) BOOL beepOnRead;
@property(nullable, nonatomic, weak) id<GXEntityDataFieldBarCodeScannerDelegate> scannerDelegate;

@optional
@property(nullable, nonatomic, copy) NSArray<NSString *> *scannerBarcodeTypes; // GXBarcodeType_...

@end

// Linear Barcodes
extern NSString *const GXBarcodeType_UPCECode;
extern NSString *const GXBarcodeType_Code39Code;
extern NSString *const GXBarcodeType_Code39Mod43Code;
extern NSString *const GXBarcodeType_EAN13Code;
extern NSString *const GXBarcodeType_EAN8Code;
extern NSString *const GXBarcodeType_Code93Code;
extern NSString *const GXBarcodeType_Code128Code;
extern NSString *const GXBarcodeType_Interleaved2of5Code;
extern NSString *const GXBarcodeType_ITF14Code;

// 2D Barcode
extern NSString *const GXBarcodeType_PDF417Code;
extern NSString *const GXBarcodeType_QRCode;
extern NSString *const GXBarcodeType_AztecCode;
extern NSString *const GXBarcodeType_DataMatrixCode;

NS_ASSUME_NONNULL_END
