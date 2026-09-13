#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
//基本思想：节点数据+节点相互关系

//法一：子表表示法（孩子表示法）
//树看作节点表，其中表的每个元素又是一个子表
//节点表的长度依赖于树的节点数，一般顺序表示
//节点表储存子表表头指针
//子表长度依赖于子节点的度，一般链式表示
//子表的链接顺序依赖于树中的左右次序

struct EdgeNode{//子表节点定义
    int node_pos;//在nodelist中的位置
    struct EdgeNode *link;
};

struct ChiTreeNode{//节点表定义
    //节点表中储存树的所有节点
    data_type info;
    struct EdgeNode* children//表头指针
};

struct ChiTree{//树定义
    int MAXNUM;
    int root;//根节点下标
    int n;//节点个数
    struct ChiTreeNode* nodelist;
};

//总的来说，这种储存方法是非递归的。因为所有节点共用一个总表。
//它只显式包含了节点的孩子信息，而兄弟关系需要通过链表表示
//它的缺点是难以找父节点。必须要遍历一遍树才能找到。
//遍历一遍节点表，看它的表头指针指向的子表中有没有节点的地址
//找右兄弟，需要找到父节点的子表。

int parent_chitree(PChiTree t,int p) 
{ 
    int i; 
    struct EdgeNode *v; 
    for (i = 0; i < t->n;i++){ 
    /*逐个检查树的各个结点,是不是父结点*/  
        v = t->nodelist[i].children;
        /*若检查的结点子表中有p,则返回值是该结点的位置*/
        while(v!=NULL) 
        {   
            if (v->nodeposition == p) return(i); 
            else v = v->link; 
        } 
    } 
    return –1; /*无父结点,则返回值为-1*/ 
} 

int rightSibling_chitree(PChiTree t,int p){
    int i; 
    struct EdgeNode *v; 
    for (i=0; i < t->n; i++){ 
        v = t->nodelist[i].children; 
        while (v!=NULL) { 
            if (v->nodeposition == p) {
                if (v->link==NULL) return –1; 
                else return v->link->nodeposition; 
            } 
            else v = v->link; 
        }
    } 
    return –1; 
} 




//静态长子兄弟表示法
//节点储存节点数据，以及三个指针（在数组中用下标即可）
//分别指向父节点，最左子节点，右兄弟节点
//优点：方便找父亲，兄弟，孩子等基本操作
//方便插入子树（调整三个指针即可）（前提是储存在同一个数组里）
//空间效率高

//动态长子兄弟表示法中，节点储存指向长子和右兄弟的指针和数据
struct CSNode{
    datatype info;
    struct CSNode* lchild;
    struct CSNode* rsibling;

};

//优点：方便找子女兄弟，且可以方便地合并树，且不会浪费空间
//缺点：不方便找父节点（需要从根节点开始遍历，找长子是该节点的节点）

