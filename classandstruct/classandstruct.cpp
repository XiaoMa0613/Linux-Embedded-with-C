/*C++中的类和C语言中的结构体类似,C++中的类和Python的类很类似*/
#include <iostream>
using namespace std;

class Animal
{
    public:
        int age;
        int weight; //类属性
        Animal(void); //构造函数
        ~Animal(void) //当对象脱离其作用域时（例如对象所在的函数已调用完毕），系统自动执行析构函数
        {
            cout<<"~Animal()..."<<endl;
        }
        virtual void speak() //虚函数用来实现多态，允许使用父类指针来调用子类的继承函数
        {
            cout<<"Animal speaking..."<<endl; 
        }
};

Animal :: Animal(void) //外部构造类函数
{
    cout<<"Animal()..."<<endl;
}

class Cat:public Animal //创建子类 ，继承父类
{
    public:
        char sex;
        Cat(void){cout<<"Cat()..."<<endl;}
        ~Cat(void){cout<<"~Cat()..."<<endl;}
        void speak() //重定义类方法
        {
            cout<<"cat speaking...miaomiao"<<endl;
        }
        void eat(void)//定义自己的类方法
        {
            cout<<"cat eating..."<<endl;
        }
};

int main(void)
{
    Cat cat;
    Animal *p = &cat;
    p->speak();
    cat.speak(); //使用了virtual关键字定义了虚函数speak；子类的重定义会覆盖。
}