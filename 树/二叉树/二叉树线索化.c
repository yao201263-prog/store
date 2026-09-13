#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//前序字符串（#代表NULL）
char str[]="ABDH#K###E##CFI###G#J##\0";

typedef struct TreeNode{
    ElemType data;
    int ltag,rtag;//tag为0代表子树，tag为1代表线索
    TreeNode* leftChild;
    TreeNode* rightChild;
}TreeNode;

typedef TreeNode* biTr;//二叉树

biTr* initTree(){//返回指向根节点的指针的二级指针
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root->data='';
    root->ltag=0; root->rtag=0;
    root->leftChild=NULL; root->rightChild=NULL;
    return &root;
}

int idx=0;//全局变量，记录前序字符串的索引

void createTree(biTr* t){//利用前序字符串创建树
    ElemType ch;
    ch=str[idx++];
    if(ch=='#'){
        *t=NULL;//*t代表biTr本身
    }else{
        *t=(biTr)malloc(sizeof(TreeNode));
        (*t)->data=ch;//处理数据域
        (*t)->ltag=0; (*t)->rtag=0;//初始化tag
        createTree(&(*t)->leftChild);//处理左右孩子
        createTree(&(*t)->rightChild);
    }
}

TreeNode* prev =NULL;//全局变量，记录前驱节点
//具体线索化
void threading(biTr t){
   if(t!=NULL){
        threading(t->leftChild);
        if(t->leftChild==NULL){
            t->ltag=1;
            t->leftChild=prev;
        }
        if(prev->rightChild==NULL){
            prev->rtag=1;
            prev->rightChild=t;
        }
        prev=t;
        threading(t->rightChild);
   }

}

//中序线索化:
//首个节点左指针指向head;
//最后一个节点右指针指向head;
//head左指针指向根;
//head右指针指向最后一个节点
//(首个或最后一个都是指中序顺序)

void inOrderThreading(biTr t,biTr* head){
    //头节点处理
    *head=(TreeNode*)malloc(sizeof(TreeNode));
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->rightChild=(*head);

    if(t == NULL){
        (*head)->leftChild = *head;
    }else {
        (*head)->leftChild = t;
        // 线索化前，prev 指向 head，使中序首个节点的左线索指向 head
        prev = *head;
        threading(t);//执行完成后prev指向尾。
        // 收尾：中序最后一个节点（此时在 prev 中）右线索指向 head
        prev->rtag = 1;
        prev->rightChild = *head;
        // head 右指针指向中序最后一个节点
        (*head)->rightChild = prev;
    }

}


void inOrderTraverse_Thr(biTr head){
    biTr p = head->leftChild;

    while(p != head){
        while(p->ltag == 0){
            p = p->leftChild;
        }

        printf("%c ", p->data);

        while(p->rtag == 1 && p->rightChild != head){
            p = p->rightChild;
            printf("%c ", p->data);
        }

        p = p->rightChild;
    }
}
