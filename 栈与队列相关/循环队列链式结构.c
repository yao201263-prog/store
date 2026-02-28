#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

Queue* initQueue(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=0; 
    node->next=NULL;
    q->front=node;
    q->rear=node;
    return q;
}

int isEmpty(Queue* q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}

void push(Queue* q,int newData){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=newData;
    newNode->next=NULL;

    q->rear->next=newNode;
    q->rear=newNode;
}

int pop(Queue* q,int* e){
    if(isEmpty(q)){
        printf("队列为空！无法执行弹出\n");
        return 0;
    }
    //弹出头节点的下一个节点
    Node* temp=q->front->next;
    *e=temp->data;
    q->front->next=temp->next;
    if(q->rear==temp){
        q->rear=q->front;
    }
    free(temp);
    return 1;
}

int getFront(Queue* q,int* e){
    if(isEmpty(q)){
        printf("队列为空！\n");
        return 0;
    }
    *e=q->front->next->data;
    return 1;
}

int getRear(Queue* q,int* e){
    if(isEmpty(q)){
        printf("队列为空！\n");
        return 0;
    }
    *e=q->rear->data;
    return 1;
}

int main(){
    Queue* q=initQueue();
    int e;
    push(q,1);
    push(q,2);
    push(q,3);
    getFront(q,&e);
    printf("队首元素：%d\n",e);
    getRear(q,&e);
    printf("队尾元素：%d\n",e);
    pop(q,&e);
    printf("弹出元素：%d\n",e);
    getFront(q,&e);
    printf("新的队首元素：%d\n",e);
}
