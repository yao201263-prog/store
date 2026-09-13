#include <stdio.h>

typedef struct object {
    int key;
} DataType;

void swap(DataType *a, DataType *b) {
    DataType temp = *a;
    *a = *b;
    *b = temp;
}

int Partition1(DataType R[], int l, int r) {
    DataType temp = R[l];  // 以表首元素为枢轴
    int i = l, j = r;

    while (i < j) {
        while (i < j && R[j].key >= temp.key) {
            j--;
        }
        while (i < j && R[i].key <= temp.key) {
            i++;
        }
        if (i < j) {
            swap(&R[i], &R[j]);
        }
    }

    swap(&R[l], &R[i]);
    return i;
}

void quickSort(DataType *pvector, int l, int r) {
    if (l < r) {
        int pivot = Partition1(pvector, l, r);
        quickSort(pvector, l, pivot - 1);
        quickSort(pvector, pivot + 1, r);
    }
}

void printArray(DataType R[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", R[i].key);
    }
    printf("\n");
}

int main() {
    DataType R[] = {{49}, {38}, {65}, {97}, {76}, {13}, {27}, {49}};
    int n = sizeof(R) / sizeof(R[0]);

    printf("排序前: ");
    printArray(R, n);

    quickSort(R, 0, n - 1);

    printf("排序后: ");
    printArray(R, n);

    return 0;
}
