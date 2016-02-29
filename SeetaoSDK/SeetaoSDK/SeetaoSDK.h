//
//  seetaoSDK.h
//  seetaoSDK
//
//  Created by Olesee on 15/5/19.
//  Copyright (c) 2015年 olesee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "SeetaoShareContent.h"
#import "SeetaoNavigationController.h"
#import "SeetaoUser.h"

///异步操作完成的回调, 参数为是否成功
typedef void (^SeetaoOperationCompleteBlock)(BOOL success);

#pragma mark --Share
///WebView回调代理, 推荐使用:SeetaoSDKShareBlock
__deprecated
@protocol SeetaoWebViewCallBackDelegate <NSObject>

@optional
/**
 @brief Webview分享代理方法, 不再推荐使用, 请用: SeetaoSDKShareBlock代替
 @see callBackDelegate
 @param title       分享的标题
 @param content     分享的内容
 @param imageUrl    分享的图片Url地址
 @param url         分享的网页Url地址
 @param successBlock   分享成功后回调Block
 @param failureBlock   分享失败后回调Block
 */
- (void)shareTitle:(NSString *)title
           content:(NSString *)content
          imageUrl:(NSURL *)imageUrl
               url:(NSString *)url
      successBlock:(void(^)()) successBlock
      failureBlock:(void(^)(BOOL userCanceled))failureBlock __deprecated;


@end

/**
 @brief 分享回调
 @see SeetaoShareContent
 @param container 分享动作发生时所在的视图控制器
 @param content 分享的内容和配置
 */
typedef void (^SeetaoSDKShareBlock)(UIViewController *container, SeetaoShareContent *content);

#pragma mark --h5/native bridge
/**
 @brief 导航接口, 打开App本地页面
 @return 返回是否成功调用
 */
typedef BOOL (^SeetaoSDKNavigationOpenBlock)(UIViewController *vc, NSString *string);


/**
 @brief h5直接调用App的回调接口
 @param result 回调返回的数据
 */
typedef void (^SeetaoSDKCallBackBlock)(NSDictionary *restult);

/**
 @brief h5直接调用App的接口, 返回是否支持该调用
 @param vc h5的调用请求发生时所在的viewController实例
 @param data h5调用请求的参数
 @param callback h5调用请求的回调函数
 @return 返回是否成功调用
 */
typedef BOOL (^SeetaoSDKCallMethodBlock)(UIViewController *vc,
                                   NSDictionary *data,
                                   SeetaoSDKCallBackBlock callback);

#pragma mark --Account
///登录成功的回调
typedef void (^SeetaoSDKSignInSuccessBlock)(SeetaoUser *user);
///登录失败的回调, 参数为是否因为用户主动取消的登录流程
typedef void (^SeetaoSDKSignInFailureBlock)(BOOL userCanceled);

/**
 @brief 提供给App和h5之间共享用户昵称、头像等用户信息的能力，在吐槽、抽奖等多种互动中用到
 */
@protocol SeetaoUserDelegate <NSObject>

@required
/**
 @brief app当前的用户信息
 */
- (SeetaoUser *)currentUser;

@required
/**
 @brief 如果上一个函数返回的空，且需要强认证(例如: 吐槽、抽奖)的互动, 则会调用App的这个协议来强制用户登录
 */
- (void)signInWithViewController:(UIViewController *)viewController
                    successBlock:(SeetaoSDKSignInSuccessBlock)successBlock
                   failureBlock:(SeetaoSDKSignInFailureBlock)failureBlock;

@end

#pragma mark --SDK Object 
@interface SeetaoSDK : NSObject
///是否打印调试信息当debug设为YES时打印调试信息
@property (assign, nonatomic) BOOL debug;

///分享回调接口, App分享获得结果(成功、失败、取消)之后需要回调 shareSuccessBlock, 或者 shareFailureBlock
@property (copy, nonatomic) SeetaoSDKShareBlock shareBlock;

///导航打开接口, SDK中运行的H5请求打开App本地页面, 页面地址是string类型，建议编码成URL格式
@property (copy, nonatomic) SeetaoSDKNavigationOpenBlock navigationOpenBlock;

///h5调用应用本地接口, App如果需要实现和自定义h5交互, 需要实现该接口
@property (copy, nonatomic) SeetaoSDKCallMethodBlock callMethodBlock;

///app名称, 推荐使用: shakeTitle 或者 shakeTitleImage 来定义摇一摇页面标题
@property (copy, nonatomic) NSString *appName __deprecated;
///摇一摇标题
@property (copy, nonatomic) NSString *shakeTitle;
///摇一摇标题图片
@property (strong, nonatomic) UIImage *shakeTitleImage;

///关闭按钮图片, 关闭当前的导航栈, 对应dismiss操作
@property (strong, nonatomic) UIImage *shakeCloseImage;
///返回按钮图片, 返回上一个页面, 对应pop操作或者WebView的 goBack操作
@property (strong, nonatomic) UIImage *shakeBackImage;

///摇一摇页面背景颜色
@property (copy, nonatomic) UIColor *shakeViewBackgroundColor;
///摇一摇页面外面大圈颜色
@property (copy, nonatomic) UIColor *shakeLargeCircleColor;
///摇一摇页面小圈颜色
@property (copy, nonatomic) UIColor *shakeSmallCircleColor;
///视淘标识字体颜色
@property (copy, nonatomic) UIColor *logoTextColor;
///摇一摇中间图片
@property (copy, nonatomic) UIImage *shakeImage;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
/**
 @brief Webview代理
 @see SeetaoWebViewCallBackDelegate
 */
@property (weak, nonatomic) id<SeetaoWebViewCallBackDelegate> callBackDelegate;
#pragma clang diagnostic pop

/**
 @brief 用户信息相关的代理
 @see SeetaoUserDelegate
 */
@property (weak, nonatomic) id<SeetaoUserDelegate> userDelegate;
/**
 @brief 视淘SDK单例方法。
 */
+ (SeetaoSDK *)sharedSDK;

/**
 @brief 初始化视淘SDK方法,需在程序启动时在AppDelegate中调用
 @param appId  在视淘SDK开放平台申请的appid
 @param secret 在视淘SDK开放平台申请的appid对应的secret
 */
- (void)setUpWithAppId:(NSString *)appId secret:(NSString *)secret;

/**
 @brief 用push方法展示摇一摇界面
 @param navController  用来推出摇一摇页面的导航控制器
 */
- (void)pushShakeViewControllerIn:(UINavigationController *)navController;

/**
 @brief 用present方法展示摇一摇界面
 @param viewController  用来弹出摇一摇页面的视图控制器
 @param completionBlock 弹出摇一摇页面完成后的block回调
 */
- (void)presentShakeViewControllerIn:(UIViewController *)viewController
                          completion:(void (^)(void)) completionBlock;

/**
 @brief 当App的用户改变时，需要调用这个方法来通知开放平台更新当前的用户信息
 */
- (void)signInWithUser:(SeetaoUser *)user
       completionBlock:(SeetaoOperationCompleteBlock)completionBlock;
/**
 @brief 当App用户退出时需要调用退出登录的接口通知开放平台用户退出登录
 */
- (void)signOutCurrentUser:(SeetaoOperationCompleteBlock)completionBlock;

@end




