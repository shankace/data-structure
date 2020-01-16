#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Stack.h"
#include "Queue.h"

typedef struct TNode* BinTree;
#define NULL 0;

struct TNode
{
    /* 树的节点 */
    int Data;
    BinTree Left;
    BinTree Right;
};

// void InorderTraversal(BinTree T)
// {
//     if(T)
//     {
//         InorderTraversal(T->Left);
//         printf("%d ", T->Data);
//         InorderTraversal(T->Right);
//     }
// }

// void PreorderTraversal(BinTree T)
// {
//     if(T)
//     {
//         printf("%d ", T->Data);
//         InorderTraversal(T->Left);
//         InorderTraversal(T->Right);
//     }
// }

// void PostorderTraversal(BinTree T)
// {
//     if(T)
//     {
//         InorderTraversal(T->Left);
//         InorderTraversal(T->Right);
//         printf("%d ", T->Data);
//     }
// }

// void InorderTraversal_nr(BinTree T)
// {
//     /* 非递归版本的中序遍历。中序遍历是在从左树返回时遇到结点访问。 */
//     struct Stack_Node * s = Stack_Init();
//     BinTree BT = T;
//     while(BT || !Stack_IsEmpty(s))
//     {
//         while(BT)
//         {
//             Stack_Push(s, BT);
//             BT = BT->Left;
//         }
//         BT = Stack_Pop(s);
//         printf("%d ", BT->Data);
//         BT = BT->Right;
//     }
// }

void LevelTraversal(BinTree T)
{
    /* 层序遍历 */
    BinTree BT = T;
    Queue q = Queue_Init();
    Queue_Add(q, BT);
    while(!Queue_IsEmpty(q))
    {
        BinTree tmp = Queue_Delete(q);
        printf("%d ", tmp->Data);
        if(tmp->Left)
            Queue_Add(q, tmp->Left);
        if(tmp->Right)
            Queue_Add(q, tmp->Right);
    }
}

BinTree BinTree_Init()
{
    Queue q = Queue_Init();
    BinTree BT, T;
    BT = (BinTree)malloc(sizeof(struct TNode));
    /* 初始化根结点 */
    int data;
    scanf("%d", &data);
    BT->Data = data;
    BT->Left = BT->Right = NULL;
    Queue_Add(q, BT);
    while(!Queue_IsEmpty(q))
    {
        T = Queue_Delete(q);
        scanf("%d", &data);
        if(data!=0)
        {
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = data;
            T->Left->Left = T->Left->Right = NULL;
            Queue_Add(q, T->Left);
        }
        else
            T->Left == NULL;
        scanf("%d", &data);
        if(data!=0)
        {
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = data;
            T->Right->Left = T->Right->Right = NULL;
            Queue_Add(q, T->Right);
        }
        else
            T->Right == NULL;
    }
    return BT;
}

int main(int argc, char const *argv[])
{
    BinTree bt = BinTree_Init();
    LevelTraversal(bt);
    getchar();
    return 0;
}