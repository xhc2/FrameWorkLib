//
//  LvpSwitchStreamBean.h
//  IosMedia
//
//  Created by mrx on 2020/11/25.
//  Copyright © 2020 mrx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LvpSwitchStreamBean : NSObject
    @property (nonatomic , weak) NSArray *backUpUrls;
    @property int switchFlag;

@end

NS_ASSUME_NONNULL_END
