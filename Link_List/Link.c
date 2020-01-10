#include<stdio.h>
#include<stdlib.h>

#define ERROR NULL

typedef struct Link * ProLink;

struct Link{
    int Data;
    ProLink Next;
};


ProLink Insert(ProLink p, int k, int x){
    /* p为链表的头指针，初始化的时候为NULL，p链表的尾指针应该指向NULL,
    添加节点时有头尾和中间三种不同情况，链表有空链表和非空链表两种情况。*/
    ProLink p1 = p;
    ProLink tmp = (ProLink)malloc(sizeof(struct Link));
    tmp->Next = NULL;
    tmp->Data = x;
    int i = 0;
    // 判断链表是否为空
    if(!p1 && k!=1){
        printf("这个链表为空，不能再第%d处添加元素\n", k);
        return ERROR;
    }
    if(!p1 && k==1){
        p1 = (ProLink)malloc(sizeof(struct Link));
        p1->Next = tmp;
        return p1;
    }
    if(p1 && k==1){
        tmp->Next = p1->Next;
        p1->Next = tmp;
        return p1;
    }
    while(p1 && i<k-1){
        i++;
        p1 = p1->Next;
    }
    if(!p1){
        printf("%d超出范围", k);
        return ERROR;
    }
    if(!p1->Next){
        p1->Next = tmp;
        return p;
    }
    else{
        tmp->Next = p1->Next;
        p1->Next = tmp;
        return p;
    }
}

ProLink Search(ProLink p, int k){
    ProLink p1 = p;
    int i = 0;
    if(!p1){
        printf("这是个空链表\n");
        return ERROR;
    }
    else{
        while(p1->Next && i<k){
            i++;
            p1 = p1->Next;
        }
        if(i==k){
            printf("%d\n",p1->Data);
            return p;
        }
        else{
            printf("超出范围\n");
            return p;
        }
    }
    
}

ProLink Delete(ProLink p, int k){
    /* 删除节点的时候应该释放内存 */
    ProLink p1 = p;
    int i = 0;
    if(!p1){
        printf("这是一个空链表");
    }
    else{
        while(p1->Next && i<k-1){
            i++;
            p1 = p1->Next;
        }
        if(i==k-1){
            ProLink tmp = p1->Next;
            p1->Next = tmp->Next;
            free(tmp);
            return p;
        }
    }
}

ProLink Traversal(ProLink p){
    ProLink p1 = p;
    if(!p1){
        printf("空链表");
        return ERROR;
    }
    while(p1->Next){
        p1 = p1->Next;
        printf("%d ", p1->Data);
    }
    printf("\n");
    return p;
}



int main(int argc, char const *argv[])
{
    ProLink p=NULL;
    p = Insert(p, 1, 2);
    p = Insert(p, 1, 1);
    p = Insert(p, 3, 3);
    p = Insert(p, 4, 4);
    p = Traversal(p);
    p = Search(p, 1);
    p = Search(p, 2);
    p = Search(p, 3);
    p = Traversal(p);
    p = Delete(p, 1);
    p = Traversal(p);
    p = Delete(p, 2);
    p = Traversal(p);
    p = Delete(p, 2);
    p = Traversal(p);
    getchar();
    return 0;
}
