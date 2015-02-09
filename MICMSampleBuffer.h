//  MICMSampleBuffer.h
//  MovieMaker
//
//  Created by Kevin Meaney on 02/01/2015.
//  Copyright (c) 2015 Kevin Meaney. All rights reserved.

@import Foundation;
@import AVFoundation;


/// A wrapper for a CMSampleBuffer to manage sample buffer allocation lifetime.
@interface MICMSampleBuffer : NSObject <NSCopying>

/// Copy initializer. Designated initializer.
-(instancetype)initWithMICMSampleBuffer:(MICMSampleBuffer *)sampleBuffer;

/// Initialize with a CMSampleBuffer. Designated initializer.
-(instancetype)initWithCMSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/// copy this object method.
-(instancetype)copy;

/// Retains the sampleBuffer and releases previously owned buffer.
-(void)setCMSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/// Returns the CMSampleBuffer.
-(CMSampleBufferRef)CMSampleBuffer CF_RETURNS_NOT_RETAINED;

@end
