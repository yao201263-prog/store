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

//删除第k个节点（包括尾节点）
void deleteNode(List *list,int k){
	if(list->size==0){
		printf("链表为空！无法操作");
		return;
	}
	
	if(k>list->size||k<0){
		printf("越界错误！链表长度为%d\n",list->size);	
		return;
	}
	
	if(k==0){
		Node* ptr=list->head;
		list->head=list->head->next;
		free(ptr);
	}else if(k<list->size){
		Node* ptr=list->head;
		for(int i=0;i<k-1;i++){
			ptr=ptr->next;
		}//执行后ptr指向第k-1个节点
		Node* temp=ptr->next;
		ptr->next=ptr->next->next;//第k-1个节点尾指针指向第k+1个节点
		free(temp);
	}else{
		Node* ptr=list->head;
		for(int i=0;i<k-1;i++){
			ptr=ptr->next;
		}//执行后指针指向链表尾节点的前一个节点
		Node* temp = ptr->next;
		ptr->next = NULL;
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