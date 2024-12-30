#include<stdio.h>
#define MAX 100

int matrix[MAX][MAX];

void initArray(int col, int row);
void printArray(int row, int col);

int main() {
    int col, row;
    printf("Nhap so hang (row): ");
    scanf("%d", &row);
    printf("Nhap so cot (col): ");
    scanf("%d", &col);
    if (row > MAX || col > MAX || row <= 0 || col <= 0) {
        printf("Kich thuoc hang va cot phai trong khoang 1 den %d.\n", MAX);
        return 1;
    }
    initArray(col, row);
    printArray(row, col);

    return 0;
}
void initArray(int col, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("matrix[%d][%d]= ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printArray(int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

