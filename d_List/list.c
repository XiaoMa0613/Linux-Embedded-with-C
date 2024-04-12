#include <stdlib.h>
#include <stdio.h>
#include "list.h"

doube_LinkedList listinit(int data)
{
    Node *dL;
    dL = (Node *)malloc(sizeof(Node));
    if(NULL == dL)
    {
        printf("create failed!\n");
        exit(0);
    }
    dL->next = NULL;
    dL->data = data;
    dL->pre = NULL;
    return dL;
}

//双向链表的头插法
void LinkedListCreatH(doube_LinkedList header, Node *new)
{
    new->next = header->next;
    if(header->next == NULL)
        header->next->pre = new;
    header->next = new;
    new->pre = header;
}

//双向链表的尾插
void LinkedListCreatT(doube_LinkedList header, Node *new)
{
    Node *p = header;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = new;
    new->pre = p;
}

//双向链表的正向遍历
void LinkedList_for_each(doube_LinkedList header)
{
    Node *p = header;
    while(p->next != NULL)
    {
        p = p->next;
        printf(p->data);
    }

}

//双向链表的反向遍历
void LinkedList_for_each_nx(doube_LinkedList header)
{
    Node *p = header;
    while(NULL != p->next)
    {
        p = p->next;
    }

    while(p->pre != NULL)
    {
        printf("%d\n", p->data);
        p = p->pre;
    }
}

int LinkedList_delete(doube_LinkedList header, int data)
{
    Node *p = header;
    while(p->next != NULL)
    {
        p = p->next;
        if(p->data == data)
        {
            if(p->next != NULL)
            {
                p->next->pre = p->pre;
                p->pre->next = p->next;
                free(p);
            }
            else
            {
                p->pre->next = NULL;
                free(p);
            }
            return 0;
        }
    }
    printf("\n没有找到节点或节点已被删除")；
    return -1;
}