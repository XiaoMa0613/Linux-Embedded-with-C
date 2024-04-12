#include <stdio.h>
//根据结构体的某一成员变量地址，获得这个结构体的首地址
/*type 结构体类型
member 结构体内的成员
ptr 结构体成员member的地址*/
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
/*求出成员与结构体首地址的地址偏移
在下面的例子中
offsetof展开就是(size_t) &((struct student *)0)->num = 0000000000000004  （64位电脑）

*/
#define container_of(ptr, type, member) ({ \
    const typeof( ((type *)0)->member )*__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) ); \
})
/*typeof()用于返回一个变量的类型
const typeof( ((type *)0)->member )*__mptr = (ptr);寻求member成员的地址，
使用typeof是兼容各种数据类型
整个宏定义返回的值为语句表达式的最后一条语句，即(type *)( (char *)__mptr - offsetof(type,member) ); 
(type *)强行转换输出的指针
*/

struct student
{
    int age;
    int num;
    int math;
};

int main(void)
{
    struct  student stu;
    printf("%p\n",&stu);
    struct student *p;
    p = container_of(&stu.num, struct student, num);
    printf("%p\n", p);
    return 0;
    
}
