#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

extern struct TNode;
typedef struct TNode* BinTree;
typedef struct Link_Node * Link;

struct Link_Node
{
    BinTree Data;
    Link Next;
};

typedef struct Queue_Node *Queue;

struct Queue_Node
{
    Link Head;
    Link Rear;
};

Queue Queue_Init()
{
    Queue q;
    q->Head = (Link)malloc(sizeof(struct Link_Node));
    q->Rear = q->Head;
    q->Head->Data = NULL;
    q->Rear->Next = NULL;
    return q;
}

bool Queue_Add(Queue q, BinTree BT)
{
    Link tmp_link = (Link)malloc(sizeof(struct Link_Node));
    tmp_link->Data = BT;
    tmp_link->Next = NULL;
    q->Rear = tmp_link;
    q->Head->Next = tmp_link;
    return true;
}

bool Queue_IsEmpty(Queue q)
{
    return q->Head->Next==NULL;
}

BinTree Queue_Delete(Queue q)
{
    if(Queue_IsEmpty(q))
    {
        printf("队列为空\n");
        return false;
    }
    else
    {
        Link l = q->Head->Next;
        BinTree BT = l->Data;
        q->Head->Next = l->Next;
        free(l);
        return BT;
    }
}