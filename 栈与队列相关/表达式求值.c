#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char exp[] = "(1+2)*3-4/2";

typedef struct Node {
    int *data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack *initStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

int isEmpty(Stack *s) {
    if (s->top == NULL) {
        return 1;
    }
    return 0;
}

void push(Stack *s, int *e) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    int *val = (int *)malloc(sizeof(int));
    *val = *e;
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s, int *e) {
    if (isEmpty(s)) {
        printf("空的\n");
        return 0;
    }
    Node *temp = s->top;
    *e = *(temp->data);
    s->top = s->top->next;
    free(temp->data);
    free(temp);
    return 1;
}

int getTop(Stack *s, int *e) {
    if (isEmpty(s)) {
        printf("空的\n");
        return 0;
    }
    *e = *(s->top->data);
    return 1;
}

int freeStack(Stack *s) {
    while (s->top != NULL) {
        Node *temp = s->top;
        s->top = s->top->next;
        free(temp->data);
        free(temp);
    }
    free(s);
    return 1;
}

typedef enum {
    LEFT_PAREN, RIGHT_PAREN, ADD, SUB, MUL, DIV, END, NUM
} Op;

Op getToken(const char *exp, int *index) {  // 获取下一个运算符
    char ch = exp[*index];
    (*index)++;
    switch (ch) {
        case '(': return LEFT_PAREN;
        case ')': return RIGHT_PAREN;
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MUL;
        case '/': return DIV;
        case '\0': return END;
        default:  return NUM;
    }
}

int precedence(Op op) {
    switch (op) {
        case ADD:
        case SUB: return 1;
        case MUL:
        case DIV: return 2;
        default:  return 0;
    }
}

// 从操作数栈和运算符栈各取元素计算一次，结果压回操作数栈
void evalOnce(Stack *numStack, Stack *opStack) {
    int op1, op2, opToken;
    pop(opStack, &opToken);
    pop(numStack, &op2);
    pop(numStack, &op1);
    int result;
    switch ((Op)opToken) {
        case ADD: result = op1 + op2; break;
        case SUB: result = op1 - op2; break;
        case MUL: result = op1 * op2; break;
        case DIV: result = op1 / op2; break;
        default: result = 0;
    }
    push(numStack, &result);
}

void eval() {
    Stack *numStack = initStack();  // 操作数栈
    Stack *opStack  = initStack();  // 运算符栈
    int index = 0;
    Op token = getToken(exp, &index);  // 获取第一个token

    while (token != END) {  // 当扫描未结束
        if (token == NUM) {
            int val = exp[index - 1] - '0';
            push(numStack, &val);  // 数字入栈
        } else if (token == LEFT_PAREN) {
            int t = (int)token;
            push(opStack, &t);  // 左括号入运算符栈
        } else if (token == RIGHT_PAREN) {
            // 遇到右括号，弹出运算符直到左括号
            int topOp;
            while (!isEmpty(opStack)) {
                getTop(opStack, &topOp);
                if ((Op)topOp == LEFT_PAREN) {
                    pop(opStack, &topOp);  // 弹出左括号
                    break;
                }
                evalOnce(numStack, opStack);
            }
        } else {
            // 遇到运算符，先弹出栈中优先级>=当前的运算符计算
            int topOp;
            while (!isEmpty(opStack)) {
                getTop(opStack, &topOp);
                if ((Op)topOp == LEFT_PAREN || precedence((Op)topOp) < precedence(token)) break;
                evalOnce(numStack, opStack);
            }
            int t = (int)token;
            push(opStack, &t);  // 当前运算符入栈
        }
        token = getToken(exp, &index);  // 获取下一个运算符
    }

    // 处理剩余运算符
    while (!isEmpty(opStack)) {
        evalOnce(numStack, opStack);
    }

    int result;
    pop(numStack, &result);  // 弹出结果
    printf("结果是：%d\n", result);

    freeStack(numStack);
    freeStack(opStack);
}

//中缀表达式转后缀表达式
void toPostfix() {
    Stack *opStack = initStack();  // 运算符栈
    int index = 0;
    Op token = getToken(exp, &index);  // 获取第一个token

    printf("后缀表达式：");
    while (token != END) {
        if (token == NUM) {
            printf("%c ", exp[index - 1]);  // 数字直接输出
        } else if (token == LEFT_PAREN) {
            int t = (int)token;
            push(opStack, &t);  // 左括号入栈
        } else if (token == RIGHT_PAREN) {
            int topOp;
            while (!isEmpty(opStack)) {
                getTop(opStack, &topOp);
                if ((Op)topOp == LEFT_PAREN) {
                    pop(opStack, &topOp);  // 弹出左括号，丢弃
                    break;
                }
                pop(opStack, &topOp);
                printf("%c ", "+-*/"[(Op)topOp - ADD]);  // 括号内运算符依次输出
            }
        } else {
            int topOp;
            while (!isEmpty(opStack)) {
                getTop(opStack, &topOp);
                if ((Op)topOp == LEFT_PAREN || precedence((Op)topOp) < precedence(token)) break;
                pop(opStack, &topOp);
                printf("%c ", "+-*/"[(Op)topOp - ADD]);  // 弹出优先级>=当前的运算符输出
            }
            int t = (int)token;
            push(opStack, &t);  // 当前运算符入栈
        }
        token = getToken(exp, &index);  // 获取下一个token
    }

    // 将剩余运算符依次输出
    int topOp;
    while (pop(opStack, &topOp)) {
        printf("%c ", "+-*/"[(Op)topOp - ADD]);
    }
    printf("\n");

    freeStack(opStack);
}



int main() {
    eval();
    toPostfix();
    return 0;
}