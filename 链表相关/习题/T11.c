#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int num;//编号
    struct Node* next;
} Node;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    // 建循环链表
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 1; i <= n; i++){
        Node* node = (Node*)malloc(sizeof(Node));
        node->num = i;
        if(!head){
            head = node;
            tail = node;
            node->next = head;
        } else {
            tail->next = node;
            tail = node;
            tail->next = head;
        }
    }

    // prev始终是当前要删节点的前驱
    Node* prev = tail; // 从尾节点开始，下一个就是1号
    int remaining = n;
    while(remaining--){
        // 往前数k步，找到第k个节点
        for(int i = 0; i < k-1; i++){
            prev = prev->next;
        }
        Node* del = prev->next;
        if(remaining != n-1) printf(" ");
        printf("%d", del->num);
        prev->next = del->next;
        free(del);
    }
    printf("\n");

    return 0;
}