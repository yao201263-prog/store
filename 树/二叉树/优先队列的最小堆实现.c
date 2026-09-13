#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct TreeNode {
    type data;
    struct TreeNode* lc;
    struct TreeNode* rc;
} tn;

typedef tn*  bitr;   // 一级指针（指向节点）
typedef bitr* pbitr; // 二级指针（指向树根指针）

/* ── 堆结构：用完全二叉树 + size 计数 ── */
typedef struct min_heap {
    pbitr t;    // 指向根节点指针的二级指针
    int   size; // 当前元素个数（补充字段，必要）
} m0h;
typedef m0h* pm0h;

typedef struct priority_queue {
    pm0h h;
} pq;
typedef pq* ppq;

/* ════════════════════════════════════════
   内部辅助：按层序路径找第 k 个节点(1-based)
   路径思路：k 的二进制表示（去掉最高位 1）
   逐位决定走左(0)还是走右(1)
   ════════════════════════════════════════ */
static bitr* find_node_ptr(pbitr root_ptr, int k) {
    /* 返回指向第 k 个节点指针的地址，方便插入/删除时修改父节点的 lc/rc */
    if (k == 1) return root_ptr;

    /* 收集从根到目标节点的路径位（去掉最高位） */
    int path[32], depth = 0;
    int n = k;
    while (n > 1) {
        path[depth++] = n & 1; // 0=左, 1=右
        n >>= 1;
    }
    /* path[depth-1] 是根的直接子方向，path[0] 是最后一步 */
    bitr* cur = root_ptr; // cur 是指向当前节点指针的地址
    for (int i = depth - 1; i >= 1; i--) {
        bitr node = *cur;
        cur = (path[i] == 0) ? &node->lc : &node->rc;
    }
    /* 最后一步 */
    bitr node = *cur;
    return (path[0] == 0) ? &node->lc : &node->rc;
}

/* 交换两个节点的 data（不换指针，保持树形不变） */
static void swap_data(bitr a, bitr b) {
    type tmp = a->data;
    a->data  = b->data;
    b->data  = tmp;
}

/* ════════════════════════════════════════
   初始化
   ════════════════════════════════════════ */
void init_tree(pbitr t) {
    *t = NULL; // 空树：根指针置 NULL
}

void init_heap(pm0h h) {
    h->t    = (pbitr)malloc(sizeof(bitr));
    h->size = 0;
    init_tree(h->t);
}

void init_pq(ppq q) {
    q->h = (pm0h)malloc(sizeof(m0h));
    init_heap(q->h);
}

/* ════════════════════════════════════════
   判空
   ════════════════════════════════════════ */
int isEmpty(ppq q) {
    return q->h->size == 0;
}

/* ════════════════════════════════════════
   上浮（sift-up）：从节点 k 向上调整
   ════════════════════════════════════════ */
static void sift_up(pbitr root_ptr, int k) {
    while (k > 1) {
        int parent = k / 2;
        bitr* pk = find_node_ptr(root_ptr, k);
        bitr* pp = find_node_ptr(root_ptr, parent);
        if ((*pp)->data > (*pk)->data)
            swap_data(*pp, *pk);
        else
            break;
        k = parent;
    }
}

/* ════════════════════════════════════════
   下沉（sift-down）：从节点 k 向下调整
   ════════════════════════════════════════ */
static void sift_down(pbitr root_ptr, int k, int size) {
    while (1) {
        int left  = 2 * k;
        int right = 2 * k + 1;
        int smallest = k;

        if (left <= size) {
            bitr* pl = find_node_ptr(root_ptr, left);
            bitr* ps = find_node_ptr(root_ptr, smallest);
            if ((*pl)->data < (*ps)->data) smallest = left;
        }
        if (right <= size) {
            bitr* pr = find_node_ptr(root_ptr, right);
            bitr* ps = find_node_ptr(root_ptr, smallest);
            if ((*pr)->data < (*ps)->data) smallest = right;
        }
        if (smallest == k) break;

        bitr* pk  = find_node_ptr(root_ptr, k);
        bitr* psm = find_node_ptr(root_ptr, smallest);
        swap_data(*pk, *psm);
        k = smallest;
    }
}

/* ════════════════════════════════════════
   push：插入元素
   ════════════════════════════════════════ */
void push(type x, ppq q) {
    pm0h h = q->h;
    h->size++;
    int k = h->size;

    /* 在第 k 个位置创建新节点 */
    bitr* slot = find_node_ptr(h->t, k);
    *slot = (bitr)malloc(sizeof(tn));
    (*slot)->data = x;
    (*slot)->lc   = NULL;
    (*slot)->rc   = NULL;

    /* 上浮维护堆性质 */
    sift_up(h->t, k);
}

/* ════════════════════════════════════════
   front：获取最小值（不弹出）
   ════════════════════════════════════════ */
void front(type* x, ppq q) {
    if (isEmpty(q)) return;
    *x = (*(q->h->t))->data; // 根节点即最小值
}

/* ════════════════════════════════════════
   pop：弹出最小值
   ════════════════════════════════════════ */
void pop(ppq q) {
    if (isEmpty(q)) return;
    pm0h h = q->h;
    int  k = h->size;

    /* 将最后一个节点的值移到根 */
    bitr* root_ptr = h->t;
    bitr* last_ptr = find_node_ptr(root_ptr, k);
    (*root_ptr)->data = (*last_ptr)->data;

    /* 释放最后一个节点并断开连接 */
    free(*last_ptr);
    *last_ptr = NULL;
    h->size--;

    /* 下沉维护堆性质 */
    if (h->size > 0)
        sift_down(root_ptr, 1, h->size);
}

/* ════════════════════════════════════════
   测试
   ════════════════════════════════════════ */
int main(void) {
    pq  queue;
    ppq q = &queue;
    q->h  = NULL;
    init_pq(q);

    int vals[] = {5, 3, 8, 1, 4, 2, 7};
    int n = sizeof(vals) / sizeof(vals[0]);

    printf("push: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vals[i]);
        push(vals[i], q);
    }
    printf("\n");

    printf("pop order (min-heap): ");
    while (!isEmpty(q)) {
        type x;
        front(&x, q);
        printf("%d ", x);
        pop(q);
    }
    printf("\n");

    return 0;
}