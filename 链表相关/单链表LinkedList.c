#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表 Linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} List;

//创建大小为n的，data为0的链表并返回头节点指针
Node* createList(int n){
	if(n==0)return NULL;
	Node *head=(Node*)malloc(sizeof(Node));
	head->data=0;
	head->next=NULL;
	Node* tail=head;
	for(int i=1;i<n;i++){
		tail->next=(Node*)malloc(sizeof(Node));
		tail=tail->next;
		tail->data=0;
		tail->next=NULL;		
	}
	return head;
}

//直接创建n个节点的链表
void cList(List* list,int n){
	list->head=createList(n);
	list->size=n;
}

//释放整个链表空间
void freeList(List *list){
	Node* current = list->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->size = 0;
}

//在第k个节点后插入新节点
void insertNode(List *list,int k,int newData){
	if(k<0||k>list->size){
		printf("插入位置不合法！\n");
		return;
	}
	
	if(k<list->size){
		Node *arrow=list->head;
		for(int i=0;i<k;i++){
			arrow=arrow->next;
		}//执行完成后，arrow指向第k个节点
	
		Node* newNode=(Node*)malloc(sizeof(Node));
		newNode->data=newData;
		newNode->next=arrow->next;
		arrow->next=newNode;
		list->size++;
	}else if(k==0){	
		Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = list->head; // 新节点指向原头节点
        list->head = newNode;      // 新节点作为头节点
        list->size++;	
	}else{
		Node* arrow = list->head;
        // 找到最后一个节点
        while (arrow->next != NULL) {
            arrow = arrow->next;
        }
        
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = NULL;  // 尾部节点的next为NULL
        arrow->next = newNode; // 原最后一个节点指向新节点
        list->size++;
	}		
}

//删除第k个节点（包括头尾节点），k从1开始计数
void deleteNode(List *list, int k){
    if(list->size == 0){
        printf("链表为空！无法操作\n");
        return;
    }
    
    // k的有效范围是1到size（包含）
    if(k < 1 || k > list->size){
        printf("越界错误！链表长度为%d，k=%d不合法\n", list->size, k);
        return;
    }
    
    // 删除头节点（k=1）
    if(k == 1){
        Node* ptr = list->head;
        list->head = list->head->next;
        free(ptr);
    }
    // 删除尾节点（k=size）
    else if(k == list->size){
        Node* ptr = list->head;
        // 找到倒数第二个节点
        for(int i = 0; i < list->size - 2; i++){
            ptr = ptr->next;
        }
        Node* temp = ptr->next;  // 这是尾节点
        ptr->next = NULL;  // 倒数第二个节点的next设为NULL
        free(temp);
    }
    // 删除中间节点
    else{
        Node* ptr = list->head;
        // 找到第k-1个节点（要删除节点的前一个节点）
        for(int i = 0; i < k - 2; i++){
            ptr = ptr->next;
        }
        Node* temp = ptr->next;  // 这是要删除的第k个节点
        ptr->next = ptr->next->next;  // 跳过第k个节点，连接第k+1个节点
        free(temp);
    }
    list->size--;
}

//设置第k个节点的数据
void setData(List* list,int k,int Data){
    if (k < 0 || k >= list->size) {
        printf("越界错误！链表长度为%d\n", list->size);
        return;
    }
    
    if (list->size == 0) {
        printf("链表为空！无法操作\n");
        return;
    }
    
    Node* arrow = list->head;
    for (int i = 0; i < k; i++) {
        arrow = arrow->next;
    } // 执行完成后，arrow指向第k个节点
    
    arrow->data = Data;
    printf("已将第 %d 个节点的数据设置为 %d\n", k, Data);
}

//查找链表中首个值为Data的元素并返回对应指针或NULL
Node* findData(List *list,int Data){
	if (list->size == 0) {
        printf("链表为空！\n");
        return NULL;
    }
    
    Node* arrow = list->head;
    while (arrow != NULL) {
        if (arrow->data == Data) {
            return arrow; // 找到节点，返回指针
        }
        arrow = arrow->next;
    }
    
    printf("未找到数据为 %d 的节点\n", Data);
    return NULL; // 未找到
}

//反转链表
void reverseList(List* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next; // 保存下一个节点
        current->next = prev; // 反转当前节点的指针
        prev = current;       // 移动prev和current指针
        current = next;
    }
    
    list->head = prev; // 更新头节点
}





int main() {
    List *list = (List*)malloc(sizeof(List));
    
    printf("========== 测试1：创建链表 ==========\n");
    cList(list, 3);
    printf("创建了3个节点的链表，size=%d\n", list->size);
    
    printf("\n========== 测试2：设置节点数据 ==========\n");
    setData(list, 0, 10);
    setData(list, 1, 20);
    setData(list, 2, 30);
    
    printf("\n========== 测试3：插入节点 ==========\n");
    insertNode(list, 0, 5);      // 头部插入
    printf("在头部插入5，size=%d\n", list->size);
    
    insertNode(list, 2, 15);     // 中间插入
    printf("在第2个节点后插入15，size=%d\n", list->size);
    
    insertNode(list, list->size, 40); // 尾部插入
    printf("在尾部插入40，size=%d\n", list->size);
    
    printf("\n========== 测试4：查找节点 ==========\n");
    Node* found = findData(list, 20);
    if (found != NULL) {
        printf("找到了值为20的节点\n");
    }
    
    found = findData(list, 100);
    if (found == NULL) {
        printf("值为100的节点未找到\n");
    }
    
    printf("\n========== 测试5：删除节点 ==========\n");
    printf("删除前的size=%d\n", list->size);
    deleteNode(list, 0);         // 删除头节点
    printf("删除头节点后size=%d\n", list->size);
    
    deleteNode(list, 2);         // 删除中间节点
    printf("删除第2个节点后size=%d\n", list->size);
    
    deleteNode(list, list->size - 1); // 删除尾节点
    printf("删除尾节点后size=%d\n", list->size);
    
    printf("\n========== 最终清理 ==========\n");
    freeList(list);
    free(list);
    
    printf("测试完成！\n");
    return 0;
}










/*
应用题：
1：导出倒数第k个节点的数据
方法：双指针法：类似于滑动区间，始终保持两个指针间距为k
使得快指针先走k步，然后快慢指针同时走，直到快指针到达链表尾部
此时慢指针所指节点即为倒数第k个节点

2两个单链表有共同后缀，找出首个公共结点
快慢指针法：
先遍历两个链表，计算出长度差d
然后让较长链表的指针先走d步
接着两个指针同时走，直到相遇
时间复杂度O(n)，空间复杂度O(1)

3单链表储存n个整数，要求对于绝对值相等的数字，
只保留其中第一个，删除其他节点，数字绝对值小于等于n；
方法：空间换时间，使用辅助数组记录绝对值是否出现过

4反转单链表
建立三个指针pre、cur、next
初始时pre指向NULL，cur指向头节点，next指向cur的下一个节点
然后遍历链表，在每一步中，将cur的next指针指向pre，然后将pre、cur、next指针依次向前移动一位
遍历结束后，pre指针将指向新的头节点 

5删除中间节点
快慢指针：快指针每次走两步，慢指针每次走一步
当快指针到达链表尾部时，慢指针正好指向中间节点
删除慢指针所指节点即可
*/