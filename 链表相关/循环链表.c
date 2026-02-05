#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//单向循环链表 circular linked list
//尾节点指向头节点
//遍历时，终止条件是指针回到头节点

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} circularList;

//创建大小为n的，data为0的循环链表并返回头节点指针
Node* createCircularList(int n){
    if(n==0)return NULL;
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=head; // 指向自己，形成循环
    Node* tail=head;
    for(int i=1;i<n;i++){
        tail->next=(Node*)malloc(sizeof(Node));
        tail=tail->next;
        tail->data=0;
        tail->next=head; // 继续指向头节点		
    }
    return head;
}

//直接创建n个节点的循环链表
void ccList(circularList* list,int n){
    list->head=createCircularList(n);
    list->size=n;
}

//滑动k次指针
Node* movePointer(Node* start, int k) {
    Node* arrow = start;
    for (int i = 0; i < k; i++) {
        arrow = arrow->next;
    }
    return arrow;
}

//检测结构中是否有环
int iscList(Node* head){
    // 空链表无环
    if (head == NULL) {
        return 0;
    }
    // 使用快慢指针法检测环并返回环长度
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {//遍历链表
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // 计算环的长度
            int length = 1;
            Node* current = slow->next;// 从相遇点开始计数
            while (current != slow) {// 遍历环
                length++;
                current = current->next;
            }
            return length; // 返回环的长度
        }
    }
    return 0; // 无环
}

