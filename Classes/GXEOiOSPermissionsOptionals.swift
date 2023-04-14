//
//  GXEOiOSPermissionsOptionals.swift
//  CDDSD
//

import GXCoreBL
import GXCoreUI

extension GXEOiOSPermissions: GXEOiOSPermissionsLocationOptionals {

	@objc(gxRequestWhenInUseAuthorization)
	public static func gxRequestWhenInUseAuthorization() {
		self.gxRequestWhenInUseAuthorization(withCompletionHandler: nil)
	}

	@objc(gxRequestWhenInUseAuthorizationWithCompletionHandler:)
	public static func gxRequestWhenInUseAuthorization(withCompletionHandler completionHandler: (() -> ())?) {
		if GXLocationManager.shared().locationManager.gxAuthorizationStatus == .notDetermined {
			GXLocationManagerPermissionsHelper.sharedInstace.requestAuhtorization(withMode: .whenInUse, completionHandler: completionHandler)
		}
	}

	@objc(gxRequestAlwaysAuthorization)
	public static func gxRequestAlwaysAuthorization() {
		self.gxRequestAlwaysAuthorization(withCompletionHandler: nil)
	}

	@objc(gxRequestAlwaysAuthorizationWithCompletionHandler:)
	public static func gxRequestAlwaysAuthorization(withCompletionHandler completionHandler: (() -> ())?) {
		if GXLocationManager.shared().locationManager.gxAuthorizationStatus == .notDetermined {
			GXLocationManagerPermissionsHelper.sharedInstace.requestAuhtorization(withMode: .always, completionHandler: completionHandler)
		}
	}
}

private class GXLocationManagerPermissionsHelper : NSObject, CLLocationManagerDelegate {
	fileprivate enum LocationAuthorizationMode {
		case always
		case whenInUse
	}

	public static let sharedInstace: GXLocationManagerPermissionsHelper = GXLocationManagerPermissionsHelper.init()

	fileprivate var locationManager: CLLocationManager?
	fileprivate var lastAuthorizationRequestMode: LocationAuthorizationMode!

	private var locationCompletionHandler: (() -> ())?

	fileprivate func requestAuhtorization(withMode mode: LocationAuthorizationMode, completionHandler: (() -> ())? = nil) {
		self.lastAuthorizationRequestMode = mode

		gx_dispatch_on_main_queue {
			if let completionHandler = completionHandler {
				if let locationCompletionHandler = self.locationCompletionHandler {
					self.locationCompletionHandler = {
						locationCompletionHandler()
						completionHandler()
					}
				} else {
					self.locationCompletionHandler = completionHandler
				}
			}

            if self.locationManager == nil {
                self.locationManager = CLLocationManager()
				NotificationCenter.default.addObserver(self, selector: #selector(self.applicationDidBecomeActiveNotification), name: UIApplication.didBecomeActiveNotification, object: nil)
            }
            self.locationManager!.delegate = self

            switch mode {
            case .always:
                #if !os(tvOS)
				self.locationManager!.requestAlwaysAuthorization()
                #else
                assert(false, "Invalid location authorization mode for OS")
                #endif
            case .whenInUse:
                self.locationManager!.requestWhenInUseAuthorization()
            }
        }
	}

	@objc fileprivate func applicationDidBecomeActiveNotification() {
		if let locationManager = self.locationManager, locationManager.gxAuthorizationStatus == .notDetermined {
			self.requestAuhtorization(withMode: self.lastAuthorizationRequestMode)
		}
	}

	// MARK: - CLLocationManagerDelegate

	public func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
		self.commonDidChangeAuthorization(status: status)
	}

	@available(iOS 14.0, watchOS 7.0, tvOS 14.0, *)
	public func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
		self.commonDidChangeAuthorization(status: manager.authorizationStatus)
	}

	private func commonDidChangeAuthorization(status: CLAuthorizationStatus) {
		if (status != .notDetermined) {
			NotificationCenter.default.removeObserver(self, name: UIApplication.didBecomeActiveNotification, object: nil)
			self.locationManager = nil

			if let completionHandler = self.locationCompletionHandler {
				self.locationCompletionHandler = nil
				completionHandler()
			}
		}
	}
}

extension GXEOiOSPermissions: GXEOiOSPermissionsCameraOptionals {
	@objc(captureDeviceFromInput:)
	public static func captureDevice(from input: AVCaptureInput) -> AVCaptureDevice? {
		return (input as? AVCaptureDeviceInput)?.device
	}

	@objc(newCaptureDeviceInputWithDevice:)
	public static func newCaptureDeviceInput(with device: AVCaptureDevice) -> AVCaptureInput? {
		var input: AVCaptureDeviceInput? = nil
		do {
			input = try AVCaptureDeviceInput(device: device)
		}
		catch {
			GXFoundationServices.loggerService()?.logMessage(error.localizedDescription,
															 for: .general,
															 with: .error,
															 logToConsole: true)
		}
		return input
	}
}
