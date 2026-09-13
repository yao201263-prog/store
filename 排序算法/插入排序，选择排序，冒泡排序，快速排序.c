#include<stdio.h>
#include<stdlib.h>
typedef struct sortObject{
    int n;//长度
    int *a;//排序对象首部指针
}sob;

//选择排序
void* insert_sort(sob* s){
    for(int i=0;i<s->n;i++){
        int k=i;
        for(int j=i;j<s->n;j++){
            if(s->a[j]<s->a[k]){
                k=j;
            }
        }
        if(k!=i){
            int temp=s->a[i];
            s->a[i]=s->a[k];
            s->a[k]=temp;
        }
    }
} 

//冒泡排序
void* bubble_sort(sob* s){
    for(int i=0;i<s->n;i++){
        for(int j=0;j<s->n-1-i;j++){
            if(s->a[j]>s->a[j+1]){
                int temp=s->a[j];
                s->a[j]=s->a[j+1];
                s->a[j+1]=temp;
            }
        }
    }
}

//冒泡排序优化
void* bubble_sort_optimized(sob* s){
    int flag=1;
    for(int i=0;i<s->n;i++){
        flag=0;
        for(int j=0;j<s->n-1-i;j++){
            if(s->a[j]>s->a[j+1]){
                int temp=s->a[j];
                s->a[j]=s->a[j+1];
                s->a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;//如果没有发生交换，说明已经有序，直接退出循环
        }
    }
}

//插入排序
void* insert_sort(sob* s){
    for(int i=1;i<s->n;i++){
        int temp=s->a[i];//首个元素作为有序序列，从第二个元素开始插入
        int j=i-1;
        while(j>=0&&s->a[j]>temp){//将大于temp的元素向后移动一位
            s->a[j+1]=s->a[j];
            j--;
        }
        s->a[j+1]=temp;
    }
}

