#include <stdio.h>
#include <math.h>

#define MAX 100

void nhapMang(int arr[MAX][MAX], int *n, int *m) {
    printf("Nhap so hang va so cot cua ma tran: ");
    scanf("%d %d", n, m);

    printf("Nhap gia tri cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMaTran(int arr[MAX][MAX], int n, int m) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inGoc(int arr[MAX][MAX], int n, int m) {
    printf("Cac phan tu o goc:\n");
    int result[MAX][MAX] = {0};
    result[0][0] = arr[0][0];
    result[0][m - 1] = arr[0][m - 1];
    result[n - 1][0] = arr[n - 1][0];
    result[n - 1][m - 1] = arr[n - 1][m - 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void inDuongBien(int arr[MAX][MAX], int n, int m) {
    printf("Cac phan tu nam tren duong bien:\n");
    int result[MAX][MAX] = {0};

    for (int j = 0; j < m; j++) {
        result[0][j] = arr[0][j];
        result[n - 1][j] = arr[n - 1][j];
    }
    for (int i = 1; i < n - 1; i++) {
        result[i][0] = arr[i][0];
        result[i][m - 1] = arr[i][m - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void inDuongCheo(int arr[MAX][MAX], int n, int m) {
    printf("Cac phan tu tren duong cheo chinh va duong cheo phu:\n");
    int result[MAX][MAX] = {0};

    for (int i = 0; i < n && i < m; i++) {
        result[i][i] = arr[i][i];
        result[i][m - i - 1] = arr[i][m - i - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void inSoNguyenTo(int arr[MAX][MAX], int n, int m) {
    printf("Cac phan tu la so nguyen to:\n");
    int result[MAX][MAX] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPrime(arr[i][j])) {
                result[i][j] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[MAX][MAX];
    int n, m;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va duong cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n, &m);
                break;
            case 2:
                inMaTran(arr, n, m);
                break;
            case 3:
                inGoc(arr, n, m);
                break;
            case 4:
                inDuongBien(arr, n, m);
                break;
            case 5:
                inDuongCheo(arr, n, m);
                break;
            case 6:
                inSoNguyenTo(arr, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);

    return 0;
}

