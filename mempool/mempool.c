/*模拟OS/Linux的内存管理思路
实现裸机环境下的堆内存管理
*/

#include <stdio.h>
#include "mempool.h"
#define POOL_SIZE 1088
#define CHUNK_NUM 16

struct chunk{
    unsigned char *addr;
    char used;
    unsigned char size;
};

char mempool[POOL_SIZE];
struct chunk bitmap[CHUNK_NUM];
/*
内存初始化函数，初始化不同大小的16个内存块
*/
void pool_init(void)
{
    int i;
    char *p = &mempool[0];
    for (int i = 0; i < CHUNK_NUM; i++)
    {
        p = p+ i*8;
        bitmap[i].addr = p;
        bitmap[i].size = 8 * (i +1);
        bitmap[i].used = 0;
    }
}

int bitmap_index(int nbytes)
{
    if(nbytes%8 == 0)
        return nbytes / 8 -1;
    else
        return nbytes / 8;
}
/*内存申请函数*/
void* pool_malloc(int nbytes)
{
    int i;
    int index;
    index = bitmap_index(nbytes);
    for(i = index; i < CHUNK_NUM; i++)
    {
        if(bitmap[i].used == 0)
        {
            bitmap[i].used = 1;
            return bitmap[i].addr;
        }
        else
            continue;
    }
    return (void*)0;
}
/*内存释放函数*/
void pool_free(void* p)
{
    int i;
    for(i = 0; i<CHUNK_NUM; i++)
    {
        if(bitmap[i].addr == p)
            bitmap[i].used = 0;
    }
}
/*堆内存使用情况查询函数*/
void pool_info(void)
{
    int frees = 0;
    int used_size = 0;
    int i;
    for(i = 0;i<CHUNK_NUM; i++)
    {
        if(bitmap[i].used == 1)
        {
            used_size = used_size + bitmap[i].size;
        }
        else{
            frees++;
        }
    }
    printf("--------------------------\n");
    printf("          memory info          \n\n");
    printf("Total size: %d\tBytes\n", POOL_SIZE);
    printf("Used size: %d\tBytes\n", used_size);
    printf("Free size: %d\tBytes\n", POOL_SIZE - used_size);
    printf("Used Chunks: %d\n", CHUNK_NUM - frees);
    printf("Free Chunks: %d\n", frees);
    printf("pool usage: %d\%\n", (used_size*100/POOL_SIZE));
    printf("--------------------------\n");
}