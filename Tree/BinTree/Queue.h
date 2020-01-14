#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "BinTree.c"


typedef struct Queue_Node* QNode;

struct Queue_Node
{
    BinTree Data;
    Queue Next;
};

typedef struct Queue *QPtr;

struct Queue
{
    QNode Head;
    QNode Rear;
};

QPtr Queue_Init()
{
    QNode qnode = (QNode)malloc(sizeof(struct Queue_Node));
    QPtr q = (QPtr)malloc(sizeof(struct Queue));
    qnode->Data = NULL;
    qnode->Next = NULL;
    q->Head = q->Rear = NULL;
    return q;
}

bool Queue_Add(QPtr q, BinTree BT)
{
    QNode qnode = (QNode)malloc(sizeof(struct Queue_Node));
    qnode->Data = BT;
    qnode->Next = q->Rear->Next;
    q->Rear = qnode;
    return true;
}

bool Queue_IsEmpty(Qptr q)
{
    return q->Next==NULL;
}

BinTree Queue_Delete(QPtr q)
{
    if(Queue_IsEmpty(q))
    {
        printf("队列为空\n");
        return false;
    }
    else
    {
        QNode qnode = q->Head;
        BinTree BT = qnode->Data;
        q->Head = qnode->Next;
        free(qnode);
        return BT;
    }
}