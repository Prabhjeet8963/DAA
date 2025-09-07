/*
 * Performs a basic linear search on the array.
 * Returns the index of the target if found, otherwise -1.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int linearSearch(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size <= 0) 
    {
        printf("Invalid size. Must be greater than zero.\n");
        return 1;
    }

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) 
    {
        printf("Target found at index %d\n", result);
    } 
    else 
    {
        printf("Target not found\n");
    }

    return 0;
}
