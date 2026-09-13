#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int C, M;

typedef struct Student{
    char id[7];
    char name[9];
    int scores[3];  // 最多3门
    int total;
} Student;

int cmp(const void* a, const void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    if(C == 1){
        return strcmp(s1->id, s2->id);
    } else if(C == 2){
        int r = strcmp(s1->name, s2->name);
        if(r != 0) return r;
        return strcmp(s1->id, s2->id);
    } else { // C==0，按总分递减
        if(s2->total != s1->total) return s2->total - s1->total;
        return strcmp(s1->id, s2->id);
    }
}

int main(){
    int n;
    scanf("%d %d %d", &n, &M, &C);
    Student* students = (Student*)malloc(n * sizeof(Student));
    for(int i = 0; i < n; i++){
        scanf("%s %s", students[i].id, students[i].name);
        students[i].total = 0;
        for(int j = 0; j < M; j++){
            scanf("%d", &students[i].scores[j]);
            students[i].total += students[i].scores[j];
        }
    }

    qsort(students, n, sizeof(Student), cmp);

    for(int i = 0; i < n; i++){
        printf("%s %s", students[i].id, students[i].name);
        for(int j = 0; j < M; j++){
            printf(" %d", students[i].scores[j]);
        }
        printf(" %d\n", students[i].total);
    }

    free(students);
    return 0;
}