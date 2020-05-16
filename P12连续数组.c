#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define True 1
#define False 0
// 定义了一个数组类型，该数据类型的名字叫做 struct Arr,数据类型包含三个成员
struct Arr
{
    int *pBase; // 存储的是数组第一个元素的地址
    int len;    // 数组所能容纳的最大元素的个数
    int cnt;    // 当前数组有效元素的个数
};
int get();
// Inital Array
void init_arr(struct Arr *pArr, int len); // 初始化数组

void sort_arr(struct Arr *pArr);

// Show Array
void show_arr(struct Arr *pArr); // 显示数组
void inversion_arr(struct Arr *pArr);
bool append_arr(struct Arr *pArr, int val);          // 追加元素
bool insert_arr(struct Arr *pArr, int pos, int val); // 插入元素

// 删除数组元素， *val为获取函数传入参数引用的对象，传入的是int val的地址那么获取到就是val的值
bool delete_arr(struct Arr *pArr, int pos, int *val);
bool is_empty(struct Arr *pArr); // 判空数组
bool is_full(struct Arr *pArr);  // 判满数组

int main(void)
{
    struct Arr arr;
    int val;
    init_arr(&arr, 6); // 对数组进行初始化
    show_arr(&arr);    // 显示数组
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    append_arr(&arr, 6);
    if (delete_arr(&arr, 3, &val))
    {
        printf("Succeed del %d\n", val);
    }
    else
    {
        printf("Failed");
    }

    show_arr(&arr);
    inversion_arr(&arr);
    show_arr(&arr);
    sort_arr(&arr);
    show_arr(&arr);
    return 0;
}
void init_arr(struct Arr *pArr, int len)
{
    pArr->pBase = (int *)malloc(sizeof(int) * len); // 申请一个空间给数组
    if (NULL == pArr->pBase)
    {
        printf("Memory allocation Failed!\n"); // 判断内存是否为空，如果正确分配了内存则不为空
        exit(-1);                              // 终止整个程序
    }
    else
    {
        pArr->len = len;
        pArr->cnt = 0;
        // 数组初始化
    }
}

bool is_empty(struct Arr *pArr)
{
    if (pArr->cnt == 0) // 如果长度为零则为空
    {
        return True;
    }
    else
    {
        return False;
    }
}
bool is_full(struct Arr *pArr)
{
    if (pArr->cnt == pArr->len) // 如果长度等于len则满
    {
        return True;
    }
    else
    {
        return False;
    }
}

bool append_arr(struct Arr *pArr, int val)
{
    if (is_full(pArr))
    {
        return False;
    }
    else
    {
        // 有效个数元素后边追加
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;
        return True;
    }
}

bool insert_arr(struct Arr *pArr, int pos, int val)
{
    // 首先判断插入是否符合条件
    int i;
    if (is_full(pArr))
    {
        return False;
    }
    if (pos < 1 || pos > pArr->cnt + 1)
    {
        return False;
    }

    // 从第i个有效个数插入，并且大于插入的位置，每次递减
    for (i = pArr->cnt - 1; i > pos - 1; --i)
    {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }

    // 插入元素
    pArr->pBase[i - 1] = val;

    // 插入后有效元素递增
    pArr->cnt++;
    return True;
}

bool delete_arr(struct Arr *pArr, int pos, int *val)
{
    // 首先判断删除是否符合条件
    if (is_empty(pArr))
    {
        return False;
    }
    if (pos < 1 || pos > pArr->cnt)
    {
        return False;
    }
    // 返回删除的元素
    *val = pArr->pBase[pos - 1];

    // 删除或事进行元素后移
    for (int i = pos; i < pArr->cnt; i++)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return True;
}
void show_arr(struct Arr *pArr)
{
    if (is_empty(pArr))
    {
        printf("Array is empty!\n");
    }
    else
    {
        for (int i = 0; i < pArr->cnt; i++)
        {
            printf("%d", pArr->pBase[i]);
        }
        printf("\n");
        // 打印数组
    }
}

void inversion_arr(struct Arr *pArr)
{
    int i = 0;
    int j = pArr->cnt - 1;
    int t;
    while (i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }
    return;
}

void sort_arr(struct Arr *pArr)
{
    int i, j, t;
    for (i = 0; i < pArr->cnt; i++)
    {
        for (j = i + 1; j < pArr->cnt; j++)
        {
            t = pArr->pBase[i];
            pArr->pBase[i] = pArr->pBase[j];
            pArr->pBase[j] = t;
        }
    }
}