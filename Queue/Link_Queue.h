#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Data_Node* DNode;

struct Data_Node
{
    int Data;
    DNode Next;
};

typedef struct Link_Queue* LkQueue;

struct Link_Queue
{
    DNode Front, Rear;
};

LkQueue LkQNode_Init()
{
    LkQueue lq;
    lq->Front = (DNode)malloc(sizeof(struct Data_Node));
    lq->Rear = lq->Front;
    lq->Front->Data = NULL;
    lq->Front->Next = NULL;
	return lq;
} 

bool LkQueue_Add(LkQueue lq, int x)
{
    DNode tmp = (DNode)malloc(sizeof(struct Data_Node));
    tmp->Data = x;
    tmp->Next = NULL;
    lq->Rear = tmp;
    lq->Front->Next = tmp;
    return true;
}

bool LkQueue_IsEmpty(LkQueue lq)
{
    return lq->Front->Next==NULL;
}

int LkQueue_Delete(LkQueue lq)
{
    if(LkQueue_IsEmpty(lq))
    {
        printf("空队列");
        return NULL;
    }
    else
    {
        DNode tmp = lq->Front->Next; 
        int x = tmp->Data;
        lq->Front->Next = tmp->Next;
        if(!lq->Front->Next)
            lq->Rear = lq->Front;
        free(tmp);
        return x;      
    }
}