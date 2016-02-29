//
//  SeetaoShareContent.h
//  seetaoSDK
//
//  Created by Olesee on 15/9/8.
//  Copyright (c) 2015年 olesee. All rights reserved.
//

#import <Foundation/Foundation.h>

///分享成功的回调, App需要主动调用
typedef void (^SeetaoShareSuccessBlock)();

///分享失败或者取消的回调, App需要主动调用
typedef void (^SeetaoShareFailureBlock)(BOOL userCanceled);

/**
 @brief 分享的内容和配置
 */
@interface SeetaoShareContent : NSObject

///分享标题，较短, 通常可以用来做为分享到微信朋友圈的标题，或者做为微信好友的分享标题
@property (copy, nonatomic) NSString *title;

///分享内容，较长的文本, 通常可以用来显示在分享微信好友的内容区域，或者做为微博分享的内容
@property (copy, nonatomic) NSString *content;

///分享的图片URL, 通常可以做为微信朋友圈分享的缩略图
@property (copy, nonatomic) NSURL *imageUrl;

///分享的页面地址, 通常是分享到微信朋友圈之后，用户点击链接访问到的页面
@property (copy, nonatomic) NSURL *url;

///分享成功的回调, App集成分享功能之后，需要在分享成功之后调用
@property (copy, nonatomic) SeetaoShareSuccessBlock shareSuccessBlock;

///分享失败回调, App集成分享功能之后, 需要在分享被取消，或者失败之后调用
@property (copy, nonatomic) SeetaoShareFailureBlock shareFailureBlock;

@end

