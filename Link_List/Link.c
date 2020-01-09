#include<stdio.h>
#include<stdlib.h>

#define ERROR NULL

typedef struct Link * ProLink;

struct Link{
    int Data;
    ProLink Next;
};


ProLink Insert(ProLink p, int k, int x){
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
        p1->Next = NULL;
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



int main(int argc, char const *argv[])
{
    ProLink p=NULL;
    p = Insert(p, 1, 5);
    p = Insert(p, 2, 2);
    p = Insert(p, 3, 0);
    p = Insert(p, 2, 2);
    p = Insert(p, 1, 1);
    int x = Search(p, 2);
    printf("%d\n", x);
    getchar();
    return 0;
}
