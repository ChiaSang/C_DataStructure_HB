/* 郝斌数据结构指针复习 */

#include <stdio.h>
void Show_Array(int *arr, int len)
{
    printf("a[%d] = %d\n", len, *(arr + len - 1));
    //注意下标不能越界
}

int main(int argc, char const *argv[])
{
    int array[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n==============================\n");
    printf("%d  %d\n", array[3], *(array + 3));
    //这两个语句是等价的，*取变量地址的值，偏移几个地址就是取第几个值
    printf("\n==============================\n");
    Show_Array(array, 5);
    printf("\n==============================\n");

    return 0;
}
