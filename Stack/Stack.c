#include <stdio.h>
#include <stdbool.h>
#include "Link_Stack.h"

typedef int Position;

struct SNode
{
    int *Data;
    int MaxSize;
    Position Top;
};

typedef struct SNode *Stack;

Stack Init(int MAXSIZE)
{
    Stack s = (Stack)malloc(sizeof(struct SNode)); // 初始化结构指针
    /* 给指针分配一段连续的内存空间，可以直接当做数组使用 */
    s->Data = (int *)malloc(sizeof(int) * MAXSIZE);
    s->MaxSize = MAXSIZE;
    s->Top = -1;
}

bool IsFull(Stack s)
{
    return s->Top == s->MaxSize - 1;
}

bool Push(Stack s, int x)
{
    if (IsFull(s))
    {
        printf("栈已经满了");
        return false;
    }
    else
    {
        s->Data[++(s->Top)] = x;
        return true;
    }
}

bool IsEmpty(Stack s)
{
    return s->Top == -1;
}

int Pop(Stack s)
{
    if (IsEmpty(s))
    {
        return NULL;
    }
    else
    {
        return s->Data[(s->Top)--];
    }
}

void Traversal(Stack s)
{
    int i = 0;
    for (i; i <= s->Top; i++)
    {
        printf("%d ", s->Data[i]);
    }
}

int main(int argc, char const *argv[])
{
    /* Stack s = Init(10);
    Push(s, 1);
    Traversal(s);
    Push(s, 2);
    Traversal(s);
    int x = Pop(s);
    printf("%d ", x);
    Traversal(s); */
    Link_Stack pro = Link_Stack_Init();
    Link_Stack_Push(pro, 10);
    printf("%d\n", pro->Next->Data);
    getchar();
    return 0;
}
