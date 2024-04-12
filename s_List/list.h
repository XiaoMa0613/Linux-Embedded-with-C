//单节点定义
typedef struct Node
{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList listinit();
LinkedList LinkedListCreatH();
LinkedList LinkedListCreatT();
void PrintList(LinkedList L);
LinkedList LinkedListReplace(LinkedList L, int x, int k);
LinkedList LinkedListInsert(LinkedList L, int i, int x);