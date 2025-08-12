#include <stdio.h>

int main() {
    int n;

    printf("Find The minimum and maximum element from an Array\n\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) 
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Minimum value of the array is: %d.\n", min);
    printf("Maximum value of the array is: %d.\n", max);

    return 0;
}