//
//  GXAudioServices.h
//  GXCoreBL
//
//  Created by Marcos Crispino on 3/1/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXAudioRecordingManagerFormatType) {
	GXAudioRecordingManagerFormatCAF = 0,
	GXAudioRecordingManagerFormatM4A = 1,
};

extern NSString *const GXAudioRecordingServiceWarningDomain;

@protocol GXAudioRecordingService <NSObject>

- (BOOL)startRecordingWithFormat:(GXAudioRecordingManagerFormatType)format
	  shouldStopCurrentRecording:(BOOL)stopCurrentRecording
						   error:(NSError * __autoreleasing *)error;

- (NSString *)stopRecording;

- (BOOL)isRecording;

@end

NS_ASSUME_NONNULL_END
