#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Double_Stack
{
    int *Data;
    int maxsize;
    int top1, top2;
};

typedef struct Double_Stack *DStack;

DStack DStack_Init(int maxsize)
{
    DStack ds = (DStack)malloc(sizeof(int) * maxsize);
    ds->top1 = -1;
    ds->top2 = maxsize;
}

bool DStack_IsFull(DStack ds)
{
    return ds->top1 == ds->top2;
}

bool DStack_Push(DStack ds, int x, bool flag)
{
    if(DStack_IsFull(ds))
    {
        printf("栈已经满了");
        return false;
    }
    else
    {
        if(flag==true)
            ds->Data[++(ds->top1)] = x;
        else
            ds->Data[--(ds->top2)] = x;
        return true;
    }    
}


int DStack_Pop(DStack ds, bool flag)
{
    if(flag==true)
    {
        if(ds->top1==-1)
        {
            printf("第一个栈为空");
            return false;
        }
        else
            return ds->Data[ds->top1--];
    }
    else
    {
        if(ds->top2==ds->maxsize)
        {
            printf("第二个栈为空");
            return false;
        }
        else
            return ds->Data[ds->top2++];
    }
}