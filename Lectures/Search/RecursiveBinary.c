#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) 
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (arr[mid] == key)
    {
        return mid; // Key found at index mid
    }
    else if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, right, key);
    }
    else
    {
        return binarySearch(arr, left, mid - 1, key);
    }
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements(small to big):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
