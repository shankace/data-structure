#include<stdio.h>
#include<stdlib.h>

#define ERROR NULL

typedef struct Link * ProLink;

struct Link{
    int Data;
    ProLink Next;
};


ProLink Insert(ProLink p, int k, int x){
    /* 添加节点时有头尾和中间三种不同情况，并且要保证尾节点的Next指向NULL*/
    ProLink p1 = p;
    int i = 0;
    if(!p1 && k!=1){
        return ERROR;
    }
    while(p1 && i<k-2){
        i++;
        p1 = p1->Next;
    }
    if(!p1){
        ProLink p1 = (ProLink)malloc(sizeof(struct Link));
        p1->Data = x;
        p1->Next = NULL;  // 尾节点指向NULL
        return p1;
    }
    else if(p1->Next && k!=1){
        ProLink tmp = (ProLink)malloc(sizeof(struct Link));
        tmp->Data = x;
        tmp->Next = p1->Next;
        p1->Next = tmp;
        return p;
    }
    else if(p1->Next && k==1){
        ProLink tmp = (ProLink)malloc(sizeof(struct Link));
        tmp->Next = p1;
        tmp->Data = x;
        return tmp;
    }
    else{
        ProLink tmp = (ProLink)malloc(sizeof(struct Link));
        tmp->Data = x;
        tmp->Next = NULL;
        p1->Next = tmp;
        return p;
    }
}

int Search(ProLink p, int k){
    ProLink p1 = p;
    int i = 0;
    if(!p1 || k<1){
        return ERROR;
    } 
    else{
        while(i<k-1 && p1->Next){
            i++;
            p1 = p1->Next;
        }
        return p1->Data;
    }
}

ProLink Delete(ProLink p, int k){
    ProLink p1 = p;
    int i = 0;
    if(!p1 || i<1){
        return ERROR;
    }
    while(p1->Next && i<k-2){
        p1 = p1->Next;
        i++;
    }
    if(p1->Next->Next){
        p1->Next = p1->Next->Next;
        return p;
    }
    else if(p1->Next){
        p1->Next = NULL;
        return p;
    }
}

ProLink Traversal(ProLink p){
    ProLink p1 = p;
    if(!p1){
        return ERROR;
    }
    while(p1){
        printf("%d ", p1->Data);
        p1 = p1->Next;
    }
    printf("\n");
    return p;
}



int main(int argc, char const *argv[])
{
    ProLink p=NULL;
    p = Insert(p, 1, 5);
    p = Insert(p, 2, 2);
    p = Insert(p, 3, 0);
    p = Insert(p, 2, 2);
    p = Insert(p, 1, 1);
    p = Traversal(p);
    getchar();
    return 0;
}
