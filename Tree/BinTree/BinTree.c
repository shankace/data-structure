#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Stack.h"
#include "Queue.h"

typedef struct TNode* BinTree;

struct TNode
{
    /* 树的节点 */
    int Data;
    BinTree Left;
    BinTree Rigtht;
};

void InorderTraversal(BinTree T)
{
    if(T)
    {
        InorderTraversal(T->Left);
        printf("%d ", T->Data);
        InorderTraversal(T->Rigtht);
    }
}

void PreorderTraversal(BinTree T)
{
    if(T)
    {
        printf("%d ", T->Data);
        InorderTraversal(T->Left);
        InorderTraversal(T->Rigtht);
    }
}

void PostorderTraversal(BinTree T)
{
    if(T)
    {
        InorderTraversal(T->Left);
        InorderTraversal(T->Rigtht);
        printf("%d ", T->Data);
    }
}

void InorderTraversal_nr(BinTree T)
{
    /* 非递归版本的中序遍历。中序遍历是在从左树返回时遇到结点访问。 */
    Stack s = Stack_Init();
    BinTree BT = T;
    while(BT || !Stack_IsEmpty(s))
    {
        while(BT)
        {
            Stack_Push(BT);
            BT = BT->Left;
        }
        Stack tmp_T = Stack_Pop(s);
        printf("%d ", tmp_T->Data);
        BT = BT->Right;
    }
}

void LevelTraversal(BinTree T)
{
    QPtr q = Queue_Init();
    while(T)
    {
        Queue_Add(T)
    }
}