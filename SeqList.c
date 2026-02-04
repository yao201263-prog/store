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