//
//  GXAppDelegate.swift
//  CDDSD
//

import Foundation
import GXCoreBL

@objc
public class GXAppDelegate: AppDelegate_Shared {

#if DEBUG
	override public var gxShowDeveloperInfo: Bool {
		get { return true }
	}
#endif

	private lazy var gxapplicationExtensionLibraries_: [GXExtensionLibraryProtocol] = {
		var moduleClasses: [String] = []
		moduleClasses.append("GXDeviceAuthenticationExtensionLibrary")
		moduleClasses.append("LottieAnimationExtensionLibrary")
		moduleClasses.append("ImageManipulationExtensionLibrary")
		return moduleClasses.map { (moduleClassName) in
			let extLibClass = NSClassFromString(moduleClassName) as! NSObject.Type
			return extLibClass.init() as! GXExtensionLibraryProtocol
		};
	}()

	override public var gxapplicationExtensionLibraries: [GXExtensionLibraryProtocol] {
		return gxapplicationExtensionLibraries_
	}

}
