//
//  YUVView.h
//  OpenGL_YUV_detec
//
//  Created by Ruiwen Feng on 2017/5/19.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LvpVideoView : UIView

- (void)setUp;
- (void)initOpenGl:(void *)frame :(void *)win;


- (void)render:(void *)frame;
- (void)render:(void *)frame :(int)x :(int)y :(int)width :(int)height;
- (void)render:(char *)y :(char *)uv;

- (void)destroyView;

@end
