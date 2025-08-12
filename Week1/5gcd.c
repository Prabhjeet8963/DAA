#include <stdio.h>

int main() {
    int a, b, x, y;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    a = x;
    b = y;

    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD: %d\n", a);
    printf("LCM: %d\n", (x * y) / a);

    return 0;
}