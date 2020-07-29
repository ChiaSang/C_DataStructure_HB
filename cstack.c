#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct stack
{
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
void clear(PSTACK pS);
bool empty(PSTACK pS);

int main()
{
    STACK S; //STACK 等价于 struct Stack
    int val;

    init(&S);    //目的是造出一个空栈
    push(&S, 1); //压栈
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    traverse(&S); //遍历输出

while (!empty(&S))
{
    pop(&S, &val);
    printf("出栈成功，出栈的元素是%d\n", val);
}

    //clear(&S);
    //traverse(&S); //遍历输出

    if (pop(&S, &val))
    {
        printf("出栈成功，出栈的元素是%d\n", val);
    }
    else
    {
        printf("出栈失败!\n");
    }

    traverse(&S); //遍历输出

    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (pS->pTop== NULL)
    {
        printf("Failed to create a stack\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
    return;
}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    while (p != pS->pBottom)
    {
        printf("%d", p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}

bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop=pNew;
    return;
}

bool pop(PSTACK pS, int *pval)
{
    if (empty(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS->pTop;
        *pval = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
        return true;
    }
}

void clear(PSTACK pS)
{
    if (empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while (p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}