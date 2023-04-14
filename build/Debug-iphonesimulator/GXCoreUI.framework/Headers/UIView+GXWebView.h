//
//  UIView+GXWebView.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 16/3/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import WebKit;

NS_ASSUME_NONNULL_BEGIN

@protocol GXWebViewDelegateProtocol <WKUIDelegate, WKNavigationDelegate>

@end

#pragma mark -

@protocol GXWebViewProtocol <NSObject>

- (UIScrollView *)gxScrollView;
- (BOOL)gxIsLoading;
- (void)gxLoadRequest:(NSURLRequest *)request;
- (void)gxLoadHTMLString:(NSString *)string baseURL:(nullable NSURL *)baseURL;
- (void)gxUnload;
- (void)gxStopLoading;
- (void)gxReload;
- (BOOL)gxCanGoBack;
- (BOOL)gxCanGoForward;
- (void)gxEvaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^ __nullable)(__nullable id, NSError * __nullable))completionHandler;
- (void)setGXWebViewDelegate:(nullable id<GXWebViewDelegateProtocol>)delegate;
- (nullable NSURL *)gxRequestURL;

@end

#pragma mark - Helper functions

struct GXWebViewOptionsType {
	BOOL scalePageToFit;
	BOOL defaultToInitialScale1;
	
	BOOL allowsInlineMediaPlayback;
	BOOL mediaPlaybackRequiresUserAction;
	BOOL suppressesIncrementalRendering;
	BOOL shareAppSession;
};

typedef struct GXWebViewOptionsType GXWebViewOptionsType;
#define GXWebViewDefaultOptions ((GXWebViewOptionsType){NO, NO, NO, YES, NO, NO})

UIView<GXWebViewProtocol> *NewGXWebView(CGRect frame, BOOL scalePageToFit);

UIView<GXWebViewProtocol> *NewGXWebViewWithOptions(CGRect frame, GXWebViewOptionsType options);

#pragma mark - WKWebView

@interface WKWebView (GXWebViewImplementationProtocol) <GXWebViewProtocol>

@end

NS_ASSUME_NONNULL_END
