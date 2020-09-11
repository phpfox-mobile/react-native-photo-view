//
//  UIImageViewTap.h
//  Momento
//
//  Created by Michael Waterfall on 04/11/2009.
//  Copyright 2009 d3i. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <SDWebImage/UIImageView+WebCache.h>
#import <SDWebImage/SDWebImageDownloader.h>

// Import from the FLAnimated image CocoaPod if it's available.
#if __has_include(<FLAnimatedImage/FLAnimatedImageView.h>)
#import <FLAnimatedImage/FLAnimatedImageView.h>
#import <FLAnimatedImage/FLAnimatedImage.h>
// Import from the version within SDWebImage otherwise.
#elif __has_include(<SDWebImage/FLAnimatedImageView.h>)
#import <SDWebImage/FLAnimatedImageView.h>
#elif __has_include(<SDWebImageFLPlugin/FLAnimatedImageView+WebCache.h>)
#import <SDWebImageFLPlugin/FLAnimatedImageView+WebCache.h>
#endif
#import <React/RCTComponent.h>
#import <React/RCTResizeMode.h>



@protocol MWTapDetectingImageViewDelegate;

@interface MWTapDetectingImageView : FLAnimatedImageView {}

@property (nonatomic, weak) id <MWTapDetectingImageViewDelegate> tapDelegate;
@property (nonatomic, weak) UITouch * touch;

@end

@protocol MWTapDetectingImageViewDelegate <NSObject>

@optional

- (void)imageView:(UIImageView *)imageView singleTapDetected:(UITouch *)touch;
- (void)imageView:(UIImageView *)imageView doubleTapDetected:(UITouch *)touch;
- (void)imageView:(UIImageView *)imageView tripleTapDetected:(UITouch *)touch;

@end
