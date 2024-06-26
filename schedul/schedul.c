#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int task_delay[4]={0};
void task1(void)
{
    task_delay[0] = 10;
    printf("task1...\n");
}

void task2(void)
{
    task_delay[1] = 5;
    printf("task2...\n");
}

void task3(void)
{
    task_delay[2] = 2;
    printf("task3...\n");
}

void task4(void)
{
    task_delay[3] = 1;
    printf("task4...\n");
}

void timer_interrupt(void)
{
    for (int i = 0;i < 4;i++)
    {
        if(task_delay[i])
            task_delay[i]--;
    }
    alarm(1);
}

void (*task[])(void) = {task1, task2, task3, task1};
void os_init(void)
{
    task_delay[0] = 10;
    task_delay[1] = 4;
    task_delay[2] = 4;
    task_delay[3] = 1;
    signal(SIGALRM, timer_interrupt); //注册中断函数
    alarm(1); //一秒产生一个中断
}

void os_schedule(void)
{
    int i;
    while(1)
    {
        for(i = 0; i<4; i++)
        {
            if(task_delay[i]==0)
            {
                task[i]();
                break;

            }
        }
    }
}

int main(void)
{
    os_init();
    os_schedule();
    return 0;
}