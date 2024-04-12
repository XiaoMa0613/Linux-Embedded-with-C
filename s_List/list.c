#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//链表初始化
LinkedList listinit()
{
    Node *L;
    L= (Node *)malloc(sizeof(Node));
    if(L==NULL)
    {
        printf("申请失败");
        exit(0);
    }
    L->next = NULL;
    return L;
}

//头插法建立单链表
LinkedList LinkedListCreatH()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    printf("test point2\n");
    int x;
    while(scanf("%d", &x) ==1 && x != 0)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

//尾插法建立单链表
LinkedList LinkedListCreatT()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    Node *r;
    r = L;
    int x;
    while(scanf("%d", &x) == 1 && x != 0)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        r ->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}

//输出单链表
void PrintList(LinkedList L)
{
    Node *p = L->next;
    int i = 0;
    while(p)
    {
        printf("第%d个元素的值为：%d\n", ++i, p->data);
        p = p->next;
    }
}

//修改元素
LinkedList LinkedListReplace(LinkedList L, int x, int k)
{
    Node *p = L -> next;
    int i = 0;
    while(p){
        if(p->next==x)
            p->data = k;
        p = p->next;
    }
    return L;
}

//单链表的插入，在地i个位置插入元素x
LinkedList LinkedListInsert(LinkedList L, int i, int x)
{
    Node *pre;
    pre = L;
    int tempi = 0;
    for(tempi = 1; tempi<i; tempi++)
    {
        pre = pre->next;
    }
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;

    return L;
}

//单链表的删除操作,删除data为x的值
LinkedList LinkedListDelete(LinkedList L, int x)
{
    Node *p, *pre;
    p = L->next;

    while(p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p); //一定要释放p，不然会丢失这一片内存管理

    return  L;
}