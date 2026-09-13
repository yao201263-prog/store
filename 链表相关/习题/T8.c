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

void mergeList(DList* l1, DList* l2){
    Node* cur1 = l1->head->next;//双指针，分别遍历两个链表
    Node* cur2 = l2->head->next;

    while(cur2 != l2->tail){//未全部插入
        Node* next2 = cur2->next; // 提前保存l2下一个节点

        // 在l1中找到第一个level大于cur2->level的位置
        while(cur1 != l1->tail && cur1->level <= cur2->level){
            cur1 = cur1->next;
        }
        // 将cur2从l2中摘出
        cur2->prev->next = cur2->next;
        cur2->next->prev = cur2->prev;
        //将cur2插入l1中
        Node* p = cur1->prev;
        cur2->prev = p;
        cur2->next = cur1;
        p->next = cur2;
        cur1->prev = cur2;

        cur2 = next2;//处理l2下一个节点
    }
    // l2已清空，释放l2的哨兵节点
    free(l2->head);
    free(l2->tail);
    free(l2);
}

void insertOrdered(DList* l, Node* n){
    Node* cur = l->head->next;
    // 找到第一个level大于n->level的节点
    while(cur != l->tail && cur->level <= n->level){
        cur = cur->next;
    }
    // 插入到cur之前
    Node* p = cur->prev;
    n->prev = p;
    n->next = cur;
    p->next = n;
    cur->prev = n;
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

    //合并AB组
    mergeList(l1, l2);

    // 插入新成员（保持有序）
    int num; scanf("%d",&num);
    for(int i=0;i<num;i++){
        Node* n=(Node*)malloc(sizeof(Node));
        scanf("%s",n->name);
        scanf("%d",&n->level);
        n->prev=NULL; n->next=NULL;
        insertOrdered(l1, n);
    }

    //遍历链表输出结果
    Node* cur = l1->head->next;
    while(cur != l1->tail){
        printf("%s %d\n", cur->name, cur->level);
        cur = cur->next;
    }

    return 0;
}
