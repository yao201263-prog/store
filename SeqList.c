#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct {
    int ID;
    char name[50];
    int score;
} student;

typedef struct {
    student students[MAX_SIZE];
    int length;
} seqlist;

/* 初始化顺序表 */
void initList(seqlist* L){
    L->length = 0;
}

/* 在尾部添加元素 */
int appendElement(seqlist* L, student s){
    if (L->length >= MAX_SIZE) {
        printf("已达到最大长度，添加失败！\n");
        return 0;
    }
    L->students[L->length] = s;
    L->length++;
    return 1;
}

/* 插入元素，pos 为 1-based */
int insertElement(seqlist *L, student s, int pos){
    if (L->length >= MAX_SIZE) {
        printf("已达到最大长度，添加失败！\n");
        return 0;
    }
    if (pos < 1 || pos > L->length + 1) {
        printf("插入位置不合法（应在1到%d之间）！\n", L->length + 1);
        return 0;
    }
    for (int i = L->length; i >= pos; i--) {
        L->students[i] = L->students[i - 1];
    }
    L->students[pos - 1] = s;
    L->length++;
    return 1;
}

/* 遍历顺序表 */
void listElements(seqlist* L){
    if (L->length == 0) {
        printf("顺序表为空。\n");
        return;
    }
    for (int i = 0; i < L->length; i++) {
        printf("学生学号：%d, 学生姓名：%s, 成绩：%d\n",
               L->students[i].ID,
               L->students[i].name,
               L->students[i].score);
    }
}

/* 删除元素 */
int deleteElement(seqlist *L,int pos){
    if (L->length == 0) {
        printf("顺序表为空，删除失败！\n");
        return 0;
    }
    if (pos < 1 || pos > L->length) {
        printf("删除位置不合法（应在1到%d之间）！\n", L->length);
        return 0;
    }
    for (int i = pos; i < L->length; i++) {
        L->students[i - 1] = L->students[i];
    }
    L->length--;
    return 1;
}

/* 按成绩排序（升序） */
void sortScores(seqlist *L){
    for(int i=0;i<L->length-1;i++){
        for(int j=0;j<L->length-1-i;j++){
            if(L->students[j].score > L->students[j+1].score){
                student temp = L->students[j];
                L->students[j] = L->students[j+1];
                L->students[j+1] = temp;
            }
        }
    }
}

int main(){
    seqlist L;
    initList(&L);

    student s1 = {1001, "Alice", 85};
    student s2 = {1002, "Bob", 90};
    student s3 = {1003, "Charlie", 80};

    appendElement(&L, s1);
    appendElement(&L, s2);
    insertElement(&L, s3, 2);

    printf("顺序表内容：\n");
    listElements(&L);

    printf("\n按成绩排序后：\n");
    sortScores(&L);
    listElements(&L);

    printf("\n删除第2个元素后：\n");
    deleteElement(&L, 2);
    listElements(&L);

    return 0;

}




/*
动态内存版:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char name[50];
    int score;
} student;

typedef struct {
    student *students;  // 指向动态数组的指针
    int length;         // 当前元素个数
    int capacity;       // 当前容量
} seqlist;

// 初始化顺序表 
void initList(seqlist* L, int initialCapacity){
    L->students = (student*)malloc(initialCapacity * sizeof(student));
    if (L->students == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    L->length = 0;
    L->capacity = initialCapacity;
    printf("顺序表初始化成功，初始容量：%d\n", initialCapacity);
}

//扩容函数
void resizeList(seqlist* L, int newCapacity){
    student *newArray = (student*)realloc(L->students, newCapacity * sizeof(student));
    if (newArray == NULL) {
        printf("内存重新分配失败！\n");
        return;
    }
    L->students = newArray;
    L->capacity = newCapacity;
    printf("顺序表已扩容，新容量：%d\n", newCapacity);
}

// 确保有足够空间 
void ensureCapacity(seqlist* L, int minCapacity){
    if (minCapacity > L->capacity) {
        int newCapacity = L->capacity * 2;  // 容量翻倍
        if (newCapacity < minCapacity) {
            newCapacity = minCapacity;
        }
        resizeList(L, newCapacity);
    }
}

// 在尾部添加元素 
int appendElement(seqlist* L, student s){
    ensureCapacity(L, L->length + 1);
    L->students[L->length] = s;
    L->length++;
    return 1;
}

//插入元素，pos 为 1-based 
int insertElement(seqlist *L, student s, int pos){
    if (pos < 1 || pos > L->length + 1) {
        printf("插入位置不合法（应在1到%d之间）！\n", L->length + 1);
        return 0;
    }
    
    ensureCapacity(L, L->length + 1);
    
    // 将插入位置及之后的元素后移
    for (int i = L->length; i >= pos; i--) {
        L->students[i] = L->students[i - 1];
    }
    
    L->students[pos - 1] = s;
    L->length++;
    return 1;
}

// 遍历顺序表 
void listElements(seqlist* L){
    if (L->length == 0) {
        printf("顺序表为空。\n");
        return;
    }
    printf("\n====== 学生信息（容量：%d，长度：%d）======\n", L->capacity, L->length);
    for (int i = 0; i < L->length; i++) {
        printf("位置：%d, 学号：%d, 姓名：%s, 成绩：%d\n",
               i + 1,
               L->students[i].ID,
               L->students[i].name,
               L->students[i].score);
    }
    printf("==========================================\n");
}

// 删除元素 
int deleteElement(seqlist *L, int pos){
    if (L->length == 0) {
        printf("顺序表为空，删除失败！\n");
        return 0;
    }
    if (pos < 1 || pos > L->length) {
        printf("删除位置不合法（应在1到%d之间）！\n", L->length);
        return 0;
    }
    
    printf("删除学生：学号=%d, 姓名=%s, 成绩=%d\n", 
           L->students[pos-1].ID, 
           L->students[pos-1].name, 
           L->students[pos-1].score);
    
    // 将删除位置之后的元素前移
    for (int i = pos; i < L->length; i++) {
        L->students[i - 1] = L->students[i];
    }
    L->length--;
    
    // 如果长度小于容量的一半，考虑缩小容量以节省内存
    if (L->length < L->capacity / 4 && L->capacity > 4) {
        int newCapacity = L->capacity / 2;
        resizeList(L, newCapacity);
    }
    
    return 1;
}

// 按成绩排序（升序）
void sortScores(seqlist *L){
    for(int i = 0; i < L->length - 1; i++){
        for(int j = 0; j < L->length - 1 - i; j++){
            if(L->students[j].score > L->students[j + 1].score){
                student temp = L->students[j];
                L->students[j] = L->students[j + 1];
                L->students[j + 1] = temp;
            }
        }
    }
}

//查找元素 
int findElement(seqlist* L, student s){
    for(int i = 0; i < L->length; i++){
        if(L->students[i].ID == s.ID && 
           strcmp(L->students[i].name, s.name) == 0 &&
           L->students[i].score == s.score){
            return i + 1; // 返回位置（1-based）
        }
    }
    return -1; // 未找到
}

// 按学号查找 
int findElementByID(seqlist* L, int id){
    for(int i = 0; i < L->length; i++){
        if(L->students[i].ID == id){
            return i + 1; // 返回位置（1-based）
        }
    }
    return -1; // 未找到
}

// 按姓名查找 
int findElementByName(seqlist* L, const char* name){
    for(int i = 0; i < L->length; i++){
        if(strcmp(L->students[i].name, name) == 0){
            return i + 1; // 返回位置（1-based）
        }
    }
    return -1; // 未找到
}

// 获取顺序表容量 
int getCapacity(seqlist* L){
    return L->capacity;
}

// 获取顺序表长度
int getLength(seqlist* L){
    return L->length;
}

// 判断顺序表是否为空
int isEmpty(seqlist* L){
    return L->length == 0;
}

// 清空顺序表（不释放内存）
void clearList(seqlist* L){
    L->length = 0;
}

//销毁顺序表，释放内存 
void destroyList(seqlist* L){
    free(L->students);
    L->students = NULL;
    L->length = 0;
    L->capacity = 0;
    printf("顺序表已销毁，内存已释放\n");
}

// 创建学生 
student createStudent(int id, const char* name, int score){
    student s;
    s.ID = id;
    strcpy(s.name, name);
    s.score = score;
    return s;
}

int main(){
    seqlist L;
    
    // 初始化顺序表，初始容量为2（为了演示扩容效果）
    initList(&L, 2);
    
    // 创建并添加学生
    printf("\n添加学生...\n");
    appendElement(&L, createStudent(1001, "Alice", 85));
    appendElement(&L, createStudent(1002, "Bob", 90));
    printf("添加2个学生后，容量：%d，长度：%d\n", getCapacity(&L), getLength(&L));
    
    // 继续添加会触发扩容
    appendElement(&L, createStudent(1003, "Charlie", 80));
    printf("添加第3个学生后，容量：%d，长度：%d\n", getCapacity(&L), getLength(&L));
    
    // 插入学生
    printf("\n在第2个位置插入新学生...\n");
    insertElement(&L, createStudent(1004, "David", 95), 2);
    
    listElements(&L);
    
    // 查找测试
    printf("\n查找测试：\n");
    int pos = findElementByID(&L, 1003);
    if(pos != -1){
        printf("找到学号1003，位置：%d\n", pos);
    }
    
    pos = findElementByName(&L, "Bob");
    if(pos != -1){
        printf("找到Bob，位置：%d\n", pos);
    }
    
    // 排序测试
    printf("\n按成绩排序：\n");
    sortScores(&L);
    listElements(&L);
    
    // 删除测试
    printf("\n删除第2个元素：\n");
    deleteElement(&L, 2);
    printf("删除后，容量：%d，长度：%d\n", getCapacity(&L), getLength(&L));
    
    listElements(&L);
    
    // 添加更多学生测试动态扩容
    printf("\n添加更多学生测试动态扩容：\n");
    for(int i = 5; i <= 10; i++){
        char name[20];
        sprintf(name, "Student%d", i);
        appendElement(&L, createStudent(1000 + i, name, 70 + i * 2));
    }
    printf("添加10个学生后，容量：%d，长度：%d\n", getCapacity(&L), getLength(&L));
    
    // 清空列表
    printf("\n清空顺序表：\n");
    clearList(&L);
    printf("清空后，容量：%d，长度：%d\n", getCapacity(&L), getLength(&L));
    
    listElements(&L);
    
    // 销毁顺序表，释放内存
    destroyList(&L);
    
    return 0;
}


*/
