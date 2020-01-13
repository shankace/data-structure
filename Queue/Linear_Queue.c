#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Linear_Queue * LrQueue;

struct Linear_Queue
{
    int *Data;
    int MaxSize;
    int Front, Rear;
};

LrQueue LrQueue_Init(int maxsize)
{
    LrQueue lq = (LrQueue)malloc(sizeof(int)*maxsize);
    lq->MaxSize = maxsize;
    lq->Front = lq->Rear = -1;
    return lq;
}

bool LrQueue_IsFull(LrQueue lq)
{
    return (lq->Rear+1)%lq->MaxSize == lq->Front;
}

bool LrQueue_Add(LrQueue lq, int x)
{
    if(LrQueue_IsFull(lq))
    {
        printf("队列已经满了");
        return false;
    }
    else
    {
        lq->Data[++(lq->Rear)] = x;
        return true;
    }
}

bool LrQueue_IsEmpty(LrQueue lq)
{
    return lq->Rear == lq->Front;
}

int LrQueue_Delete(LrQueue lq)
{
    if(LQueue_IsEmpty(lq))
    {
        printf("队列已经空");
        return false;
    }
    else
    {
        lq->Front = (lq->Front+1) % lq->MaxSize;
        return lq->Data[lq->Front];
    }
}

int main(int argc, char const *argv[])
{

    getchar();
    return 0;
}


