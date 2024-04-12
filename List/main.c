#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    LinkedList new_list =  LinkedListCreatH();
    LinkedList list = new_list;
    // printf("test point1\n");
    while(list->next)
    {
        list = list->next;
        printf("%d\t", list->data);
    }
    printf("over");
    return 0;
}
