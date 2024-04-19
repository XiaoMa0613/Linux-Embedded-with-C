#include <stdio.h>
int global_val = 10;  //初始化的全局变量
int global_uval; //未初始化的全局变量

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int sum;
    sum = add(1, 2);
    printf("hello world!\n");
    return 0;
}