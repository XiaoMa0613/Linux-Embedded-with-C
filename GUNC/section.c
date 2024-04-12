#include <stdio.h>

int global_val = 8; //初始化的全局变量，初始化的静态局部变量都在.data段
//int uinit_val;   //未初始化的全局变量，未初始化的镜头局部变量都在.bss段
int uinit_val __attribute__((section(".data"))); //通过section属性声明，将未初始化的全局变量放在.data

void print_star(void)
{
    printf("******\n");
}
//函数定义，程序语句都在.text段
int main(void)
{
    print_star();
    return 0;
}

//gcc -o section.out section.c 编译
//查看符号表信息 readelf -s section.out
//查看section header表信息 readelf -S section.out