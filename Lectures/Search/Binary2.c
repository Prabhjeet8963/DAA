#include <stdio.h>

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements(small to big):\n", n);//Works only on Sorted array
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int high = n;
    int low = 0;
    int mid = (low + high) / 2;
    int result = -1;
    while (low<=high)
    {
        mid = (low + high) / 2;
        if(arr[mid]==key)
        {
            result = mid;
            break;
        }
        else if(key < arr[mid])
        {
            low = low;
            high = mid-1;
        }
        else
        {
            low = mid+1;
            high = high;
        }
    }

    if (result != -1)
        printf("Element found at position %d\n", result+1);
    else
        printf("Element not found\n");
    
    return 0;
}
