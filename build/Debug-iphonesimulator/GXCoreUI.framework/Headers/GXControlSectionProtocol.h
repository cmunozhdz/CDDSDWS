//
//  GXControlSectionProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/02/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlComponentProtocol.h>
#import <GXCoreUI/GXEntityDetailLayout.h>

@protocol GXControlSection <GXControlComponent>

- (id)initWithLayoutElement:(id<GXLayoutElementContent>)layoutElement
			 dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
	 businessComponentLevel:(GXBusinessComponentLevel *)businessComponentLevel
				  controlId:(NSUInteger)controlId
					 gxMode:(GXModeType)modeType
			   indexerStack:(NSArray<NSNumber *> *)indexer
			  parentControl:(id<GXControlContainer>)parentControl
					section:(GXEntityDetailLayoutSection *)section
				  relations:(NSDictionary *)relationsByDataElementName;

@property(nonatomic, strong, readonly) GXEntityDetailLayoutSection *section;
@property(assign, readonly) GXLayoutElementContentDisplayType display;

- (GXLayoutDimension)layoutElementWidth;
- (GXLayoutDimension)layoutElementHeight;

@end
