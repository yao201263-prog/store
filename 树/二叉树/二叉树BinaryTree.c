#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//二叉树
//性质1：二叉树第i层上至多有2^(i-1)个结点(i>=1)
//性质2：深度为k的二叉树至多有2^k-1个结点(k>=1)
//性质3：对于任何一棵二叉树T，如果叶子结点的个数为n0，度为2的结点个数为n2，则n0=n2+1

//特殊二叉树
//满二叉树：每一层的结点数都达到最大值的二
//完全二叉树：除最后一层外，每一层的结点数都达到最大值，且最后一层的结点都连续集中在最左边的二叉树
//性质：对于完全二叉树，如果结点总数为n，则其深度为log2(n+1)向下取整
char str[]="ABDH#K###E##CFI###G#J##\0";
//字符串从前往后，是前序遍历树的输出结果，#代表NULL
int idx=0;
//树的内容

typedef struct TreeNode{
    ElemType data;
    TreeNode* leftChild;
    TreeNode* rightChild;
}TreeNode;

typedef TreeNode* biTr;
//指向节点的指针

biTr initTree(){
    biTr t = (bitr)malloc(sizeof(TreeNode));
    t->data='';
    t->leftChild=NULL;
    t->rightChild=NULL;
    return t;
}

//前序遍历
void preOrder(biTr t){
    if(t==NULL){
        printf("#");
        return;
    }
    printf("%d",t->data);
    preOrder(t->leftChild);//先遍历左侧
    preOrder(t->rightChild);//回归右侧
}

//中序遍历
void inOrder(biTr t){
    if(t==NULL){
        printf("#");
        return;
    }
    inOrder(t->leftChild);//一直执行直至左孩子为空，此时往右走
    printf("%d",t->data);
    inOrder(t->rightChild);
}

//后序遍历
void nxtOrder(biTr t){
    if(t==NULL){
        printf("#");
        return;
    }
    nxtOrder(t->leftChild);
    nxtOrder(t->rightChild);
    printf("%d",t->data);
}
//从最左下面开始往右扫兄弟，然后再向上折回到父节点

//非递归前序遍历
void preOrder2(biTr t){
    biTr stack[100];
    int top=-1;
    biTr p=t;
    while(p!=NULL||top!=-1){
        while(p!=NULL){
            printf("%d",p->data);
            //栈结构自行实现
            stack[++top]=p;//入栈
            p=p->leftChild;//往左走
        }
        if(top!=-1){
            p=stack[top--];//出栈
            p=p->rightChild;//往右走
        }
    }
}

void createTree(biTr* t){//利用前序字符串创建树
    ElemType ch;
    ch=str[idx++];
    if(ch=='#'){
        *t=NULL;//*t代表biTr本身
    }else{
        *t=(biTr)malloc(sizeof(TreeNode));
        (*t)->data=ch;//处理数据域
        createTree(&(*t)->leftChild);//处理左右孩子
        createTree(&(*t)->rightChild);
    }
}




































