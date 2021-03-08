//
//  LvpDelegate.h
//  IosMedia
//
//  Created by mrx on 2020/11/24.
//  Copyright © 2020 mrx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LvpDelegate <NSObject>
@optional
/**
 准备成功
 **/
-(void) onPrepared;

/**
 开始加载
 **/
-(void) onLoadingBegin;

/**
 加载完毕
 **/
-(void) onLoadingEnd;


-(void) postion:(long) playTime :(long)cacheTime :(long)duration;
/**
 当前播放位置
 **/
//-(void) currentPosition:(long) playTime;
//
///**
// 当前缓冲位置
// **/
//-(void) cachePosition:(long) cacheTime;


/**
 截图回调
 **/
-(void) onSnapShot:(NSString *)path;

/**
 一些其他时间的上报
 */
-(void) onLvpEvent:(int)code : (NSString *)msg;

/**
 错误事件的上报
 **/
-(void) errorInfo:(int)code :(NSString *)msg;

/**
 播放状态回调
 **/
-(void) playState;

/*
 暂停状态回调
 */
-(void) pauseState;

/**
 第一帧回调
 **/
-(void)onRenderingStart;


/*
 seek 完成
 */
-(void)onSeekComplete;


/*
 流选择开始
 */
-(void)pickServerStart;

/*
 流选择结束
 */
-(void)pickServerEnd:(NSString *) url;

/**
 日志回调上报
 **/
-(void)logCallBack :(NSString *)log;

/**
 网络状况不好
 **/
-(void)netWorkError;

/**
 录播播放完成
 **/
-(void)finishEvent;

@end

NS_ASSUME_NONNULL_END
