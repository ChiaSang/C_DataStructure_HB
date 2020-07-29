#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
} QUEUE;

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(QUEUE *pQ);
bool en_queue(QUEUE *pQ, int val);
void traverse_queue(QUEUE *pQ);
bool full_queue(QUEUE *pQ);
bool out_queue(QUEUE *pQ, int *pval);
bool emput_queue(QUEUE *pQ);
void reverse_queue(QUEUE *pQ, int *rval);
bool pop(PSTACK, int *);
void push(PSTACK, int);

int main()
{
    QUEUE Q;
    int val;
    STACK S;

    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    en_queue(&Q, 8);

    traverse_queue(&Q);

    if (out_queue(&Q, &val))
    {
        printf("出队成功，队列出队的元素是: %d\n", val);
    }
    else
    {
        printf("出队失败!\n");
    }
    traverse_queue(&Q);
    return 0;
}

void init(QUEUE *pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}

bool emput_queue(QUEUE *pQ)
{
    if (pQ->front == pQ->rear)
        return true;
    else
        return false;
}

bool full_queue(QUEUE *pQ)
{
    if ((pQ->rear + 1) % 6 == pQ->front)
        return true;
    else
        return false;
}

void traverse_queue(QUEUE *pQ)
{
    int i;
    i = pQ->front;
    while (i != pQ->rear) //不为空的判定为队头队尾不相等
    {
        printf("%d  ", pQ->pBase[i]);
        i = (i + 1) % 6;
    }
    printf("\n");

    return;
}

bool en_queue(QUEUE *pQ, int val)
{
    if (full_queue(pQ))
    {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear + 1) % 6;
        return true;
    }
}

bool out_queue(QUEUE *pQ, int *pval)
{
    if (emput_queue(pQ))
    {
        return false;
    }
    else
    {
        *pval = pQ->pBase[pQ->front];
        pQ->front = (pQ->front + 1) % 6;
        return true;
    }
}