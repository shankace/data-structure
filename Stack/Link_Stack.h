#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Link_Node * Link_Stack;

struct Link_Node
{
    int Data;
    Link_Stack Next;
};

Link_Stack Link_Stack_Init()
{
    Link_Stack pro = (Link_Stack)malloc(sizeof(struct Link_Node));
    pro->Next = NULL;
    return pro;
}

bool Link_Stack_IsEmpty(Link_Stack pro)
{
    if(!pro->Next)
        return true;
    else
        return false; // return pro->Next == NULL; 更加简洁
}

bool Link_Stack_Push(Link_Stack pro, int x)
{
    Link_Stack tmp = (Link_Stack)malloc(sizeof(struct Link_Node));
    tmp->Data = x;
    tmp->Next = pro->Next;
    pro->Next = tmp;
    return true;
}

bool Link_Stack_Pop(Link_Stack pro)
{
    if(!Link_Stack_IsEmpty(pro))
    {   
        printf("这是个空栈\n");
        return false;
    }
    else
    {
        Link_Stack tmp = pro->Next;
        int x = tmp->Data;
        pro->Next = tmp->Next;
        free(tmp);
        return x;   
    }
}
