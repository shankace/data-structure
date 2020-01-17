#include<stdio.h>
#include<stdlib.h>
#include "BinTreeElem.h"



BinTree Insert(BinTree BST, int x)
{
    /* 二叉搜索树的插入 */
    if(!BST)
    {
        BinTree BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = x;
        BST->Left = BST->Right = NULL;
    }
    else
    {
        if(x < BST->Left->Data)
            BST = Insert(BST->Left, x);
        else if(x > BST->Right->Data)
            BST = Insert(BST->Right, x);
    }
    return BST;
}

BinTree Find(BinTree BST, int x)
{
    if(!BST)
        return NULL;
    else
    {
        if(x < BST->Data)
            BST = Find(BST->Left, x);
        else if(x > BST->Data)
            BST = Find(BST->Right, x); 
        else
            return BST;   
    }
}

BinTree Find_nr(BinTree BST, int x)
{
    /* 非递归版本搜索 */
    while(BST)
    {
        if(x < BST->Data)
            BST = BST->Left;
        else if(x > BST->Data)
            BST = BST->Right;
        else
            break;
    }
    return BST;
}

BinTree FindMax(BinTree BST)
{
    if(!BST)
        return NULL;
    else if(!BST->Right)
        return BST;
    else
        BST = FindMax(BST->Right);
}
