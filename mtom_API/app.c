/*
模仿内核源码，实现一个设备管理模块，用来完成设备的注册和管理
核心思想是：
通过回调函数实现控制反转，让系统回调我们注册到设备管理模块中的自定义函数，
高层模块和底层模块通过device_manager模块实现的抽象接口，接触模块间的耦合关系
*/

#include <stdio.h>
#include "device_manager.h"

int sd_read(void)
{
    printf("sd read data...\n");
    return 10;
}

int udisk_read(void)
{
    printf("udisk read data...\n");
    return 20;
}

struct storage_device sd = {"sdcard", sd_read};
struct storage_device udisk = {"udisk", udisk_read};

int main(void)
{
    register_device(sd); //高层模块注册函数，以便回调
    register_device(udisk);

    read_device("udisk"); //实现回调，控制反转
    read_device("udisk");
    read_device("sd");
    read_device("sdcard");
    read_device("sdcard");
    return 0;
}