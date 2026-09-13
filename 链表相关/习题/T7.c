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
    //哨兵头尾节点,不含内容数据
}DList;

typedef struct person{
    char c;
    char name[20];
}person;

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

void deleteNode(DList* l, char* name0){
    //删除代号为name0的成员
    //保证存在且唯一
    Node* cur = l->head->next;
    while(cur != l->tail){
        if(strcmp(cur->name, name0) == 0){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
            return;
        }
        cur = cur->next;
    }
}

void printList(DList* l){
    Node* cur = l->head->next;
    if(cur == l->tail){
        printf("全军覆没\n");
        return;
    }
    int first = 1;
    while(cur != l->tail){
        if(!first) printf(" ");
        printf("%s", cur->name);
        first = 0;
        cur = cur->next;
    }
    printf("\n");
}

int main(){
    int numA,numB;
    scanf("%d%d",&numA,&numB);
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

    int n; scanf("%d",&n);
    person persons[n]; //存放牺牲人员信息

    for(int i=0;i<n;i++){
        scanf(" %c %s", &persons[i].c, persons[i].name);
    }

    // 依次处理牺牲人员
    for(int i=0;i<n;i++){
        if(persons[i].c == 'A'){
            deleteNode(l1, persons[i].name);
        } else {
            deleteNode(l2, persons[i].name);
        }
    }

    printList(l1);
    printList(l2);

    return 0;
}