#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//双向链表 double linked list
//每个节点有前驱指针和后继指针
typedef struct Node{
    struct Node* ahead;
    int data;
    struct Node* next;
}Node;

//双向链表 double linked list结构体
typedef struct deList{
    Node* head;
    Node* tail;
    int size;
}deList;


//返回第k个结点指针，k从1开始到size
Node* getNodePtr(deList* list,int k){
    if(k<1||k>list->size){
        printf("越界错误！链表长度为%d，k=%d不合法\n",list->size,k);
        return NULL;
    }
    Node* ptr=list->head;
    for(int i=1;i<k;i++){
        ptr=ptr->next;
    }
    return ptr;
}


//创建大小为n的，data为0的双向链表
void createDeList(deList* list,int n) {
    Node* head = (Node*)malloc(sizeof(Node));// 创建头节点
    head->data = 0;// 初始化数据
    head->ahead = NULL;// 头节点没有前驱
    head->next = NULL;// 初始化next指针
    list->head = head;// 设置头节点
    Node* tail = head;// 初始化尾节点为头节点
    for(int i=1;i<n;i++){
        tail->next = (Node*)malloc(sizeof(Node));// 创建新节点
        tail->next->data = 0;  
        tail->next->ahead = tail;// 设置新节点的前驱为当前尾节点
        tail->next->next = NULL;// 新节点的next指针初始化为NULL
        tail = tail->next;// 更新尾节点为新节点
    }
    list->tail = tail;// 设置尾节点
    list->size = n;// 设置链表大小
    return;
}

//直接创建n个节点的双向链表
deList* cDeList(int n){
    deList* list=(deList*)malloc(sizeof(deList));
    createDeList(list,n);
    return list;
}

//在第k个节点后插入新节点
void insertNode(deList* list, int k, int data) {
    if (k < 0 || k > list->size) {
        printf("插入位置不合法！\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;// 设置新节点数据
    
    if (list->size == 0) { // 链表为空的情况
        newNode->ahead = NULL;
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else if (k == 0) { // 插入到头前
        newNode->ahead = NULL;
        newNode->next = list->head;// 新节点尾指针指向原头节点
        if (list->head != NULL) {// 如果原头节点存在
            list->head->ahead = newNode; // 更新原头节点的前驱指针
        }
        list->head = newNode; // 更新头节点
    } else if (k == list->size) { // 插入到尾部后
        newNode->ahead = list->tail;
        newNode->next = NULL;
        if (list->tail != NULL) {// 如果原尾节点存在
            list->tail->next = newNode; // 更新原尾节点的后继指针
        }
        list->tail = newNode; // 更新尾节点
    } else { // 插入到中间
        Node* current = list->head;
        for (int i = 1; i < k; i++) {
            current = current->next; // 定位到第k个节点
        }
        Node* nextNode = current->next;   
        current->next = newNode;
        newNode->ahead = current;
        newNode->next = nextNode;

        if(nextNode != NULL){
            nextNode->ahead = newNode;
        }
    }
    list->size++; // 更新链表大小
}

//删除第k个节点（包括头尾节点），k从1开始计数
void deleteNode(deList* list, int k){
    if(list->size == 0){
        printf("链表为空，无法操作！\n");
        return;
    }
    if(k < 1 || k > list->size){
        printf("越界错误！链表长度为%d\n", list->size);
        return;
    }

    Node* cur = getNodePtr(list, k);   // 待删除节点
    Node* prev = cur->ahead;
    Node* next = cur->next;

    if(prev != NULL) prev->next = next;
    else list->head = next;            // 删除头节点

    if(next != NULL) next->ahead = prev;
    else list->tail = prev;            // 删除尾节点

    free(cur);
    list->size--;
}


//设置第k个节点的数据
void setData(deList* list,int k,int data){
    if(k<=0||k>list->size){
        printf("越界错误！链表长度为%d\n",list->size);
        return;
    }
    Node* ptr=getNodePtr(list,k);
    ptr->data=data;
}

//查找链表中首个值为data的元素并返回对应指针或NULL
Node* findData(deList* list,int data){
    if(list->size==0){
        printf("链表为空！\n");
        return NULL;
    }
    Node* ptr=list->head;
    while(ptr!=NULL){
        if(ptr->data==data){
            return ptr;//找到节点，返回指针
        }
        ptr=ptr->next;
    }
    printf("值为%d的节点未找到\n",data);
    return NULL;//未找到
}


//反转双链表
void reverseList(deList* list){
    if(list->size <= 1) return;

    Node* cur = list->head;
    Node* temp = NULL;

    while(cur != NULL){
        // swap ahead 和 next
        temp = cur->ahead;
        cur->ahead = cur->next;
        cur->next = temp;

        // 反转后，原 next（现在在 ahead 中）是下一步要处理的节点
        cur = cur->ahead;
    }

    // 交换头尾
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}


//打印链表（正向遍历）
void printList(deList* list){
    if(list->size == 0){
        printf("链表为空！\n");
        return;
    }
    printf("链表内容（正向）: ");
    Node* ptr = list->head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//打印链表（反向遍历）
void printListReverse(deList* list){
    if(list->size == 0){
        printf("链表为空！\n");
        return;
    }
    printf("链表内容（反向）: ");
    Node* ptr = list->tail;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->ahead;
    }
    printf("\n");
}

//释放链表内存
void freeList(deList* list){
    Node* ptr = list->head;
    Node* temp;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp);// 释放当前节点内存
    }
    free(list);// 释放链表结构体内存
}

int main(){
    printf("========== 双向链表测试 ==========\n\n");
    
    // 测试1: 创建链表
    printf("测试1: 创建大小为5的链表\n");
    deList* list = cDeList(5);
    for(int i = 1; i <= 5; i++){
        setData(list, i, i * 10);
    }
    printList(list);
    printf("链表大小: %d\n\n", list->size);
    
    // 测试2: 插入节点
    printf("测试2: 在头部插入5\n");
    insertNode(list, 0, 5);
    printList(list);
    
    printf("测试3: 在尾部插入99\n");
    insertNode(list, list->size, 99);
    printList(list);
    
    printf("测试4: 在第3个节点后插入77\n");
    insertNode(list, 3, 77);
    printList(list);
    printf("链表大小: %d\n\n", list->size);
    
    // 测试3: 删除节点
    printf("测试5: 删除第1个节点\n");
    deleteNode(list, 1);
    printList(list);
    
    printf("测试6: 删除最后一个节点\n");
    deleteNode(list, list->size);
    printList(list);
    
    printf("测试7: 删除第3个节点\n");
    deleteNode(list, 3);
    printList(list);
    printf("链表大小: %d\n\n", list->size);
    
    // 测试4: 查找节点
    printf("测试8: 查找值为30的节点\n");
    Node* found = findData(list, 30);
    if(found != NULL){
        printf("找到节点，值为: %d\n\n", found->data);
    }
    
    // 测试5: 反向遍历
    printf("测试9: 反向遍历链表\n");
    printListReverse(list);
    printf("\n");
    
    // 测试6: 反转链表
    printf("测试10: 反转链表\n");
    reverseList(list);
    printList(list);
    printListReverse(list);
    printf("\n");
    
    // 测试7: 空链表操作
    printf("测试11: 测试空链表\n");
    deList* emptyList = (deList*)malloc(sizeof(deList));
    emptyList->head = NULL;
    emptyList->tail = NULL;
    emptyList->size = 0;
    
    printf("在空链表插入第一个元素: 100\n");
    insertNode(emptyList, 0, 100);
    printList(emptyList);
    printf("链表大小: %d\n\n", emptyList->size);
    
    // 释放内存
    freeList(list);
    freeList(emptyList);
    
    printf("========== 测试完成 ==========\n");
    return 0;
}