//
//  LvpMediaUtils.h
//  IosMedia
//
//  Created by mrx on 2020/9/24.
//  Copyright © 2020 mrx. All rights reserved.
//
/**
  是播放器的对外接口
 **/

#ifndef LvpMediaUtils_h
#define LvpMediaUtils_h



#import <UIKit/UIViewController.h>
#import "LvpDelegate.h"
#import "LvpSwitchStreamBean.h"

NS_ASSUME_NONNULL_BEGIN

@interface LvpMediaUtils : NSObject

@property (nonatomic,weak) id <LvpDelegate> delegate;

/**
 *
 * @param url 传入文件的播放地址 可以是本地地址，也可以是网络流等，例如：rtmp
 * @param logPath 传入日志文件存放地址，底层播放器的日志信息会写入此文件
 * @return >= 0 成功
 */
-(int)lvpSetMediaUrl:(const char *)url :(LvpSwitchStreamBean *)backUp :(NSString*) userName;

/**
 * 此函数主要工作打开对应的媒体问题或者网络流
 * 初始化对应的音视频的解码器。准备成功会回调一个code == 2 的状态。
 * 对应的code值 后续有专门文件维护。
 * @param time -1 从头开始播放，> 0 跳转到对应的时间去播放。
 * @param videoView 渲染的videoview实例
 * @return  >= 0 成功
 */
-(int) lvpPrepare:(long)time :(void *)videoView :(int) isLive;

/**
 *  多窗口准备工作。
 *
 * @param time  -1 从头开始播放，> 0 跳转到对应的时间去播放。
 * @param array 相关的窗口属性
 *              MuilWindowModule
 *     public Surface surface; 对应窗口的渲染窗口
 *     public int startX ;     对应渲染的视频在视频帧中的x偏移量
 *     public int startY;      对应渲染的视频在视频帧中的Y偏移量
 *     public int width ;      对应渲染的视频在视频帧中的宽度值
 *     public int height ;     对应渲染的视频在视频帧中的高度值
 * @return  >= 0 成功
 */
-(int) lvpMultiWindowPrepare:(long)time :(void **)array :(int)windowsCount;

/**
 * 开始播放
 * 需要在 lvpPrepare ， lvpMultiWindowPrepare 成功后调用
 * @return  >= 0 成功
 */
-(int)lvpStart;

/**
 * 暂停播放
 * @return  >= 0 成功
 */
-(int)lvpPause;
/**
 * 返回当前播放的时间,单位ms
 * @return  返回具体的时间 , < 0 获取失败
 */
-(int64_t)getLvpCurrentTime;

/**
 * @return > 0 就是对应的媒体的时间长度 < 0就是错误等标志
 */
-(long)getLvpMediaDuration;

/**
 * 获取视频码率
 * @return 返回码率，< 0 就是失败标志
 */
-(long)getLvpBitRate;

/**
 * 获取视频分辨率
 * @return int[0]  -> width int[1] -> height ，若为null 就是获取失败。
 */
-(int*)getLvpVideoResolution;

/**
 * @param path 传入保存路径，确保文件路径可访问。
 * @param level 输出文件标准，目前只处理了文件大小 (high 原始大小 , middle 分辨率 / 2  , low 分辨率 / 4)
 * @return path 成功，null 失败。
 */
-(char*)lvpScreenShot:(char*)path ;

/**
 * 是否静音播放（只是对播放器中的音频静音，并没有对手机的音量操作）
 * @param flag true 静音， false 非静音
 * @return  >= 0 成功
 */
-(int)lvpAudioMute:(int)flag;


/**
 * 是否循环播放
 * @param flag true 循环播放，false 普通播放
 * @return
 */
-(int)lvpLoop:(int)flag;


/**
 * 倍数播放
 * @param speed 取值范围 0.5f ~ 2.0f
 * @return  >= 0 成功
 */
-(int)lvpTempo:(float)speed;


/**
 * 跳转播放，会跳转到附近的关键帧
 * @param time 毫秒
 * @return  >= 0 成功
 */
-(int)lvpSeek:(double)pts;

/**
 * 音量控制，对设备的音量操控。
 * @param progress 取值 0-1.0f
 * @controller 对应的界面view，可以传null，
    null 调节音量的时候回有系统进度条显示
    非NULL 调节音量无系统进度条显示
 * @return   >= 0 成功
 */
-(int)lvpAudioChange:(float)progress ;


/**
 流选择
*/
-(int)lvpServerPickDebug ;

/**
  传递给底层的第一个ts
 **/
-(int)lvpFirstM3u8Ts:(const char*)ts_url;

/**
 * 停止播放，会释放所有资源。
 * @return  >= 0 成功
 */
-(int) lvpDestroy;

@end

NS_ASSUME_NONNULL_END

#endif /* LvpMediaUtils_h */
