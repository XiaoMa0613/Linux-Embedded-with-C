#include <stdio.h>

struct student{
    char sex;
    short num __attribute__((aligned(4), packed));  //按照四字节对齐
    int age;
}__attribute__((aligned(8), packed)); //8字节对齐  
//如果不加属性修饰的话，这个结构体的长度为8
int main(void)
{
    struct student stu;
    printf("&stu.sex:%p \n",&stu.sex);
    printf("&stu.num:%p \n",&stu.num);
    printf("&stu.age:%p \n",&stu.age);
    printf("struct size:%ld\n", sizeof(struct student)); //这里将变成16
    return 0;
}