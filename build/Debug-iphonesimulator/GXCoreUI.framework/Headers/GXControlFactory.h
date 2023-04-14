//
//  GXControlFactory.h
//  GXFlexibleClient
//
//  Created by willy on 5/12/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControlWithData.h>
#import <GXCoreUI/GXControlWithEvents.h>
#import <GXCoreUI/GXControlContainer.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXEntityDetailLayout.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

@interface GXControlFactory : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (nullable id <GXControl>)controlForLayoutElement:(id <GXLayoutElement>)layoutElement
									 parentControl:(id<GXControlContainer>)parentControl;

+ (id <GXControlWithData>)controlForLayoutElementData:(id <GXLayoutElementData>)layoutElementData
                                    entityDataElement:(id <GXEntityDataDescriptor>)dataDesc
                                            controlId:(NSUInteger)controlId
                                                 mode:(GXModeType)mode
                                             relation:(nullable GXBusinessComponentRelation *)relation
										 indexerStack:(nullable NSArray<NSNumber *> *)indexer
										parentControl:(id<GXControlContainer>)parentControl
                                           promptRule:(nullable id <GXEntityRulePrompt>)promptRule;

+ (id <GXControl, GXControlWithPromptRule>)controlForLayoutElementTextBlock:(id <GXLayoutElementTextBlock>)layoutElementTextBlock
                                                                  controlId:(NSUInteger)controlId
                                                                       mode:(GXModeType)mode
                                                               indexerStack:(nullable NSArray<NSNumber *> *)indexer
                                                              parentControl:(id<GXControlContainer>)parentControl
                                                                 promptRule:(nullable id <GXEntityRulePrompt>)promptRule;

+ (id <GXControlWithEvents>)controlForLayoutElementAction:(id <GXLayoutElementAction>)layoutElementAction
                                                controlId:(NSUInteger)controlId
                                                     mode:(GXModeType)mode
                                             indexerStack:(nullable NSArray<NSNumber *> *)indexer
											parentControl:(id<GXControlContainer>)parentControl
                                               promptRule:(nullable id <GXEntityRulePrompt>)promptRule;

+ (id <GXControlContainer>)controlForLayoutElementContainer:(id<GXLayoutElementContainer>)layoutElementContainer
                                                  controlId:(NSUInteger)controlId
											 dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
                                     businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
                                                       mode:(GXModeType)mode
                                               indexerStack:(nullable NSArray<NSNumber *> *)indexer
											  parentControl:(id<GXControlContainer>)parentControl
												  relations:(nullable NSDictionary *)relationsByDataElementName;

#if !TARGET_OS_WATCH
+ (id <GXControlContainer>)controlForLayoutElementContent:(id<GXLayoutElementContent>)layoutElementContent
												controlId:(NSUInteger)controlId
										   dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
								   businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
													 mode:(GXModeType)mode
											 indexerStack:(nullable NSArray<NSNumber *> *)indexer
											parentControl:(id<GXControlContainer>)parentControl
												  section:(nullable GXEntityDetailLayoutSection *)section
												relations:(nullable NSDictionary *)relationsByDataElementName;
#endif // !TARGET_OS_WATCH

+ (id <GXControl, GXControlWithPromptRule>)controlForLayoutElementImage:(id <GXLayoutElementImage>)layoutElementImage
                                                              controlId:(NSUInteger)controlId
                                                                   mode:(GXModeType)mode
                                                           indexerStack:(nullable NSArray<NSNumber *> *)indexer
                                                          parentControl:(id<GXControlContainer>)parentControl
                                                             promptRule:(nullable id <GXEntityRulePrompt>)promptRule;

@end

NS_ASSUME_NONNULL_END
