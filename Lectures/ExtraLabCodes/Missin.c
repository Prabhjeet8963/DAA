#include <stdio.h>

intNum(int arr[], int size) {
    int expectedSum = size * (size + 1) / 2; 
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;  // The missing number
}

int main() {
    int arr[] = {3, 0, 1}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing =Num(arr, size);
    printf("Missing number is: %d\n", missing);

    return 0;
}
