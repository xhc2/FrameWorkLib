/**
 * 用于回调上层处理（模拟ijkplayer 的消息机制）
 * 1.播放
 * 2.暂停
 * 3.seek 到的位置可以按百分比
 * 4.还有一些错误的状态上报
 **/

#ifndef LVP_MY_CALLBACK_H_
#define LVP_MY_CALLBACK_H_

#include "lvp_thread.h"
#include "lvp_nqueue.h"

//返回上层的播放器状态

#define VIDEO_INIT_SUCCESS 1 //初始化成功
#define VIDEO_PREPARED_SUCCESS 2 //准备成功，各种解码器已经准备完成
#define VIDEO_PLAYED_SUCCESS 3 // 播放成功
#define VIDEO_PAUSED_SUCCESS 4 //
#define VIDEO_PLAYED_FINISH 5
#define VIDEO_LOADING 6
#define VIDEO_LOADED_FINISH 7
#define SCREEN_SHOT_SUCCESS 8
#define VIDEO_SEEK_SUCCESS 9
#define FIRST_FRAME_RENDER 10
#define REINIT_VIDEO_DECODER 11
#define REINIT_VIDEO_DECODER_FINISH 12
#define PICK_SERVER_START 13
#define PICK_SERVER_END 14
#define PICK_SERVER_FINAL_CHOISE 15
#define NETWORK_STUCK_NOTIFY 16 //通过播放有点卡顿了，通知可以考虑切换了。
#define LOG_CALL_BACK 17 //通过播放有点卡顿了，通知可以考虑切换了。
#define LOG_UPLOAD_SECTION 100 //日志切片上传。



//返回上层的错误状态
#define ERROR -1
#define ERROR_OPEN_INPUT -2  //打开文件，或者网络流失败
#define ERROR_FIND_CODE -3  //找不到对应的解码器
#define ERROR_SCREEN_SHOT_NO_MEM -4 //截屏的错误，申请相关内存失败
#define ERROR_SCREEN_SHOT -5 // 截屏错误，具体的错误，请看返回的string
#define ERROR_AUDIO_PLAYER -6 // 音频播放错误
#define ERROR_OPEN_GL_SHADER -7 // 渲染错误
#define ERROR_OPEN_FIND_STREAM -8 //流错误
#define ERROR_OPEN_EGL -9 //egl等窗口相关的错误
#define ERROR_DECODE -10  //解码相关的错误
#define ERROR_PICK_SERVER -11  //流媒体相关的错误
#define ERROR_NETWORK -12  //网络状况不好，导致的问题
#define REINIT_VIDEO_DECODER_FAILD -13


#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
typedef struct message {
    int code ;
    char* msg ;
}Message;


static const struct message entry_error[] = {
    {ERROR , "ERROR" } ,
    {ERROR_OPEN_INPUT , "ERROR_OPEN_INPUT" } ,
    {ERROR_FIND_CODE , "ERROR_FIND_CODE" } ,
    {ERROR_SCREEN_SHOT_NO_MEM , "ERROR_SCREEN_SHOT_NO_MEM" } ,
    {ERROR_OPEN_EGL , "ERROR_OPEN_EGL" } ,
};

void send_error(LVPEventControl *ctl, int code , const char* msg);


void send_log(char* msg);

void send_state3(LVPEventControl *ctl, int code , const char *msg_string);


#endif
