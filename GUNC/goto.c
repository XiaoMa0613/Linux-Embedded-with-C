#include <stdio.h>
int main(void)
{
    int sum = 0;
    sum = 
    ({
        int s = 0;
        for(int i = 0; i<10; i++)
            s = s +i;
            goto here;
            s;
    });
    printf("sum=%d\n",sum);
here:
    printf("here;\n");
    printf("sum=%d\n",sum);
    return 0;
}