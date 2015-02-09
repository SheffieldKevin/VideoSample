
# VideoSample

Please see LICENSE file for license and liability information.

### Why?

The MIMovieVideoSampleAccessor class provides frame by frame access to 1 or more video tracks in a Movie using AVFoundation and works on both iOS and OSX.

I needed a video frame accessor not too dissimilar to QuickTime's next interesting time concept. I also wanted to provide random frame access, and whilst recognizing that performance will be slow for random frame access I wanted to maintain decent performance when accessing frames in time order and not too far apart. The MIMovieVideoSampleAccessor makes various compromises to achieve these goals.

Objects of this class should be accessed atomically. I achieve this in my own use by managing objects of this class as private members of objects of another class and use a gcd serial queue to manage access.

### How to Use

The simples case for creating a frame accessor assuming you want to access frames from the start of the movie, and that you want to composite all video tracks and that you want to create CGImage RGB objects which are appropriate for the runtime platform (iOS, OSX).

```objective-c
AVURLAsset *videoAsset = <...>

MIMovieVideoSampleAccessor *sampleAccessor;
sampleAccessor = [MIMovieVideoSampleAccessor alloc]  initWithMovie:videoAsset
                                                   firstSampleTime:kCMTimeZero
                                                            tracks:nil
                                                     videoSettings:nil
                                                  videoComposition:nil];
```

To obtain the next video sample (and if a video sample has yet to be requested then a video sample at the current time) you do:

```objective-c
MICMSampleBuffer *buffer = [sampleAccessor nextSampleBuffer];
```

To obtain a video sample at a specific time within the movie:

```objective-c
CMTime sampleTime = <...>
MICMSampleBuffer *buffer = [sampleAccessor sampleBufferAtTime:time];
```
