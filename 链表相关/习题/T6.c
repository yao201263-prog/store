#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    char name[20];
    int level;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct DList{
    Node* head;
    Node* tail;
    //哨兵头尾节点，不含内容数据
}DList;

DList* initList(){
    DList* l=(DList*)malloc(sizeof(DList));
    Node* head=(Node*)malloc(sizeof(Node));
    Node* tail=(Node*)malloc(sizeof(Node));
    head->prev=NULL; head->next=tail; strcpy(head->name,""); head->level=0;
    tail->prev=head; tail->next=NULL; strcpy(tail->name,""); tail->level=0;
    l->head=head; l->tail=tail;
    return l;
}

void insertNode(DList* l, Node* n){
    Node* p=l->tail->prev;
    Node* t=l->tail;
    n->prev=p; n->next=t;
    p->next=n; t->prev=n;
}

int main(){
    int numA,numB;
    scanf("%d %d",&numA,&numB);

    DList* l1=initList();
    DList* l2=initList();

    // 读入A组
    for(int i=0;i<numA;i++){
        Node* n=(Node*)malloc(sizeof(Node));
        scanf("%s",n->name);
        scanf("%d",&n->level);
        n->prev=NULL; n->next=NULL;
        insertNode(l1,n);
    }

    // 读入B组
    for(int i=0;i<numB;i++){
        Node* n=(Node*)malloc(sizeof(Node));
        scanf("%s",n->name);
        scanf("%d",&n->level);
        n->prev=NULL; n->next=NULL;
        insertNode(l2,n);
    }

    char c;
    char name[20];
    scanf(" %c",&c);
    scanf("%s",name);

    DList* target = (c=='A') ? l1 : l2;

    // 在目标链表中查找name对应节点
    Node* cur = target->head->next;
    Node* found = NULL;
    while(cur != target->tail){
        if(strcmp(cur->name, name)==0){
            found = cur;
            break;
        }
        cur = cur->next;
    }

    if(found==NULL || found->next==target->tail){
        printf("没有人");
    } else {
        Node* sub = found->next;
        printf("%s %d", sub->name, sub->level);
    }

    return 0;
}