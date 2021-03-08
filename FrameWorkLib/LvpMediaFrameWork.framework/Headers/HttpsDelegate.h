//
//  HttpsDelegate.h
//  IosMedia
//
//  Created by mrx on 2021/1/26.
//  Copyright © 2021 mrx. All rights reserved.
//

#ifndef HttpsDelegate_h
#define HttpsDelegate_h


@protocol HttpsDelegate <NSObject>
@optional
/**
 准备成功
 **/
-(void) httpSuccess:(NSString *)result;

/**
 开始加载
 **/
-(void) httpFaild:(int)code;


@end
#endif /* HttpsDelegate_h */
