//
//  SeetaoWebViewController.h
//  seetaoSDK
//
//  Created by LiZhijie on 15/5/20.
//  Copyright (c) 2015年 olesee. All rights reserved.
//

#import "SeetaoShareContent.h"

#import <UIKit/UIKit.h>

/**
 @brief SDK的Web运行环境, 集成了基础的h5/native交互的能力
 */
@interface SeetaoWebViewController : UIViewController

/**
 *@brief 配置一个默认的分享内容, 当这个不存在时会取WebView里边h5页面配置的分享内容,
         注意: 不要设置分享成功回调，分享失败回调, 只需设置要分享的内容即可
 */
@property (strong, nonatomic) SeetaoShareContent *shareContent;

///打开这个页面时需要加载的初始URL
- (instancetype)initWithUrl:(NSURL *)url;

@end
