#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

extern struct TNode;
typedef struct TNode* BinTree;

typedef struct Stack_Node* Stack;

struct Stack_Node
{
    BinTree Data;
    struct Stack_Node* Next;
};

Stack Stack_Init()
{
    Stack s = (Stack)malloc(sizeof(struct Stack_Node));
    s->Next = NULL;
    return s;
}

bool Stack_IsEmpty(Stack s)
{
    return s->Next==NULL;
}

bool Stack_Push(Stack s, BinTree T)
{
    Stack tmp = (Stack)malloc(sizeof(struct Stack_Node));
    tmp->Data = T;
    tmp->Next = s->Next;
    s->Next = tmp;
    return true;
}

BinTree Stack_Pop(Stack s)
{
    if(Stack_IsEmpty(s))
    {
        printf("这是个空栈\n");
        return NULL;
    }
    else
    {
        Stack tmp = (Stack)malloc(sizeof(struct Stack_Node));
        tmp = s->Next;
        BinTree data = tmp->Data;
        s->Next = tmp->Next;
        free(tmp);
        return data;
    }
}