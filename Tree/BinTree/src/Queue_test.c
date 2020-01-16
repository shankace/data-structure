#include "Queue.h"
#include<stdio.h>


typedef struct TNode* BinTree;
#define NULL 0;

struct TNode
{
    /* 树的节点 */
    int Data;
    BinTree Left;
    BinTree Right;
};

// int main(int argc, char const *argv[])
// {
//     // 测试队列的添加删除功能
//     Queue q = Queue_Init();
//     BinTree BT = (BinTree)malloc(sizeof(struct TNode));
//     BT->Data = 10;
//     BT->Left = BT->Right = NULL;
//     Queue_Add(q, BT);
//     BinTree t1 = Queue_Delete(q);
//     printf("%d\n", t1->Data);
//     getchar();
//     return 0;
// }