#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//栈 stack
//先进后出
//限定在一端进行插入和删除操作
//入栈 push：在栈顶插入元素
//出栈 pop：删除栈顶元素
//栈顶指针 top，初始值为-1
//栈满条件：top == maxSize - 1

#define MAX_SIZE 100

//静态内存分配：在编译时确定内存大小，通常使用数组实现
//优点：简单，访问速度快
typedef struct Stack{
    int data[MAX_SIZE];
    int top;
}Stack;

void initStack(Stack* stack){
    stack->top = -1;// 初始化栈顶指针
}

int isEmpty(Stack* stack){
    return stack->top == -1;// 栈空条件
}

int isFull(Stack* stack){
    return stack->top == MAX_SIZE - 1;// 栈满条件
}

//压栈push
int push(Stack* stack,int value){
    if(isFull(stack)){
        printf("栈满了！\n");
        return 0;// 入栈失败
    }

    stack->top++;// 栈顶指针上移
    stack->data[stack->top] = value;// 将值放入栈顶
    return 1;// 入栈成功
}

//出栈pop
int pop(Stack* stack,int *value){
    if(isEmpty(stack)){
        printf("栈空了！\n");
        return 0;// 出栈失败
    }

    *value = stack->data[stack->top];// 获取删除的栈顶元素
    stack->top--;// 栈顶指针下移
    return 1;// 出栈成功
}

//获取栈顶元素
int getTop(Stack* stack,int *value){
    if(isEmpty(stack)){
        printf("栈空了！\n");
        return 0;// 获取失败
    }

    *value = stack->data[stack->top];// 获取栈顶元素
    return 1;// 获取成功
}

//==============================================

//动态分配内存：在运行时根据需要分配内存，通常使用链表实现
//优点：灵活，内存利用率高

typedef struct{
    int* data;
    int top;
}Stack;

Stack* initStack(){
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->data = (int*)malloc(MAX_SIZE * sizeof(int));// 分配内存
    newStack->top = -1;// 初始化栈顶指针
    return newStack;
}

void freeStack(Stack* stack){
    int* p=stack->data;
    free(p);// 释放栈内存
    free(stack);// 释放栈结构体内存
}

//栈的链式结构
//头节点=栈顶
//尾节点=栈底
//压栈=头插
//出栈=头删
//判断是否空=头节点是否为NULL或头节点next是否为NULL


//栈的链式结构实现

/*
#include<stdio.h>
#include<stdlib.h>

// 栈节点结构
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// 栈结构
typedef struct Stack {
    StackNode* top;  // 栈顶指针
    int size;        // 栈大小
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// 创建栈
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    initStack(stack);
    return stack;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 获取栈大小
int getSize(Stack* stack) {
    return stack->size;
}

// 入栈（push）
void push(Stack* stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;  // 新节点指向原栈顶
    stack->top = newNode;        // 更新栈顶
    stack->size++;
}

// 出栈（pop）
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈！\n");
        return -1;  // 错误返回值
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;  // 栈顶指向下一个节点
    free(temp);
    stack->size--;
    return data;
}

// 获取栈顶元素（不出栈）
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空！\n");
        return -1;
    }
    return stack->top->data;
}

// 打印栈（从栈顶到栈底）
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空！\n");
        return;
    }
    printf("栈内容（栈顶->栈底）: ");
    StackNode* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 清空栈
void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

// 销毁栈
void destroyStack(Stack* stack) {
    clearStack(stack);
    free(stack);
}

*/