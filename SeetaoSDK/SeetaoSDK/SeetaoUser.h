//
//  SeetaoUser.h
//  seetaoSDK
//
//  Created by Olesee on 15/9/22.
//  Copyright (c) 2015年 olesee. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 @brief 开放平台中对用户信息数据结构的定义
 */
@interface SeetaoUser : NSObject

///在App中能唯一确定一个用户的唯一ID, 必选字段
@property (copy, nonatomic) NSString *uniqueId;

///用户的昵称, 可选, 但为了体验强烈建议带上
@property (copy, nonatomic) NSString *nickName;

///用户的头像地址, 可选字段, 但为了体验强烈建议带上
@property (copy, nonatomic) NSURL *avtarImageUrl;

///用户的手机号, 可选字段
@property (copy, nonatomic) NSString *phoneNumber;

@end
