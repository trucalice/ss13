#include <stdio.h>

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        if (a > b){
        b = a - b; 
        a = temp; 
	}
	  else 
	  b = b - a;
	  a = temp;
    }
    return a;  
}

int main() {
    int num1, num2;
    printf("nhap a: ");
    scanf("%d", &num1);
    printf("nhap b: ");
    scanf("%d", &num2);
    printf("uoc chung lon nhat cua %d và %d là: %d\n", num1, num2, UCLN(num1, num2));
    return 0;
}

