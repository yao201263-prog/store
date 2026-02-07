#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif
//队列 queue
//先进先出
//限定在一端进行插入，在另一端进行删除操作
//队头 front，队尾 rear，初始值为-1
//队满条件：rear == maxSize - 1 （链表队列中可以无此限制）

typedef struct Node{
	int data;
	struct Node* next;
}Node;

//链表实现队列
typedef struct Queue{
	Node* front;
	Node* rear;
}Queue;


//创建队列
Queue* initQueue(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

//队列是否空
int isEmpty(Queue* q){
	if(q->front==NULL){
		return 1;
	}
	return 0;
}



//入队函数实现：尾插
int push(Queue* q,int newData){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=newData;
	newNode->next=NULL;

	//如果队列为空
	if(q->rear == NULL){
		q->front = newNode;
		q->rear  = newNode;
		return 1;
	}

	//队列非空
	q->rear->next=newNode;
	q->rear=newNode;
	return 1;
}

//弹出函数实现：头删
int pop(Queue *q,int* e){
	//e用于接受弹出的内容
	if(isEmpty(q)){
		printf("队列为空！无法执行弹出\n");
		return 0;
	}
    
	Node* oldFront = q->front;//先保存旧节点
	*e = oldFront->data;//输出数据

	q->front = oldFront->next;//移动队头指针

	if(q->front == NULL){//如果删除后空队列，需要同步rear
		q->rear = NULL;
	}

	free(oldFront);	//释放旧节点
	return 1;
	
}

int getSize(Queue* q){
	if(isEmpty(q)){
		return 0;	
	}
	
	int size=0;
	Node* ptr=q->front;
	
	while(ptr!=NULL){
		size++;
		ptr=ptr->next;
	}
	
	return size;	
}

//释放队列
void freeQueue(Queue* q){
	Node* ptr=q->front;
	while(ptr!=NULL){
		Node* temp=ptr;
		ptr=ptr->next;
		free(temp);
	}
	free(q);	
    q=NULL;
}

int main()
{
	#ifdef _WIN32
    system("chcp 65001 > nul");  // 设置控制台代码页为 UTF-8
    SetConsoleOutputCP(CP_UTF8);  // 设置输出编码为 UTF-8
    #endif

    printf("========== 队列测试 ==========\n\n");
    
    Queue* q = initQueue();
    
    printf("入队测试：\n");
    for(int i = 1; i <= 5; i++){
        push(q, i * 10);
        printf("入队: %d, 队列大小: %d\n", i * 10, getSize(q));
    }
    
    printf("\n出队测试：\n");
    int e;
    while(!isEmpty(q)){
        pop(q, &e);
        printf("出队: %d, 队列大小: %d\n", e, getSize(q));
    }
    freeQueue(q);
    
    return 0;
}
