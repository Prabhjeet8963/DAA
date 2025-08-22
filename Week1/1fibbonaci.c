#include <stdio.h>

void Fib(int n) {

    long long a = 0, b = 1, fib;
    printf("%lld ", a);
    if (n > 0) {
        printf("%lld ", b);
    }

    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
        printf("%lld ", fib);
    }
    printf("\n");
}

int main() {
    int number;
    printf("Enter the number of terms in Fibonacci sequence: ");
    if (scanf("%d", &number) != 1 || number <= 0) {
        printf("Please enter a valid positive integer!\n");
        return 1;
    }

    Fibo(number - 1); 

    return 0;
}
