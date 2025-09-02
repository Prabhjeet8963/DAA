#include <stdio.h>
#include <math.h>
#include <time.h>

// Method 1: Using math.h
void armstrong_with_math(int n) {
    printf("\nArmstrong numbers using math.h:\n");
    for (int i = 0; i <= n; i++) {
        int temp = i, sum = 0, digits = 0;

        // Count digits
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = i;
        while (temp != 0) {
            int digit = temp % 10;
            sum += (int)pow(digit, digits);
            temp /= 10;
        }

        if (sum == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Method 2: Without using math.h
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

void armstrong_without_math(int n) {
    printf("\nArmstrong numbers without math.h:\n");
    for (int i = 0; i <= n; i++) {
        int temp = i, sum = 0, digits = 0;

        // Count digits
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = i;
        while (temp != 0) {
            int digit = temp % 10;
            sum += power(digit, digits);
            temp /= 10;
        }

        if (sum == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the upper limit (e.g., 1000): ");
    scanf("%d", &n);

    clock_t start_math = clock();
    armstrong_with_math(n);
    clock_t end_math = clock();

    clock_t start_nomath = clock();
    armstrong_without_math(n);
    clock_t end_nomath = clock();

    double time_math = (double)(end_math - start_math) / CLOCKS_PER_SEC;
    double time_nomath = (double)(end_nomath - start_nomath) / CLOCKS_PER_SEC;

    printf("\nTime using math.h: %.6f seconds", time_math);
    printf("\nTime without math.h: %.6f seconds", time_nomath);
    printf("\nTime difference: %.6f seconds\n", fabs(time_math - time_nomath));

    return 0;
}