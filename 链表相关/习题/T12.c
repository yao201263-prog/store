#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student{
    char id[7];
    char name[9];
    int score;
} Student;

int C; // 排序列号

int cmp(const void* a, const void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    if(C == 1){
        return strcmp(s1->id, s2->id);
    } else if(C == 2){
        int r = strcmp(s1->name, s2->name);
        if(r != 0) return r;
        return strcmp(s1->id, s2->id); // 姓名相同按学号递增
    } else {
        if(s2->score != s1->score) return s2->score - s1->score; // 成绩递减
        return strcmp(s1->id, s2->id); // 成绩相同按学号递增
    }
}

int main(){
    int n;
    scanf("%d %d", &n, &C);
    Student* students = (Student*)malloc(n * sizeof(Student));
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", students[i].id, students[i].name, &students[i].score);
    }
    qsort(students, n, sizeof(Student), cmp);
    for(int i = 0; i < n; i++){
        printf("%s %s %d\n", students[i].id, students[i].name, students[i].score);
    }
    free(students);
    return 0;
}