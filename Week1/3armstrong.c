#include <stdio.h>
#include <math.h>

int main() {
    int num, n = 0, sum = 0;

    printf("Enter the Number: ");
    scanf("%d", &num);  

    int temp = num;
    // 
    while (temp != 0) {
        temp /= 10;
        n++;
    }
    temp = num;  

    // Calculate the sum of digits raised to the power n
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }
    if (sum == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}