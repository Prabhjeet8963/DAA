/**
 * Performs linear search while recording each step in a journal.
 * Returns the index of the target if found, otherwise -1.
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to journal tracking
 */

#include <stdio.h>
typedef struct {
    int index;
    int value;
    int matched;
} SearchStep;

int linearSearchWithJournal(int arr[], int size, int target, SearchStep journal[]) 
{
    int foundIndex = -1;

    for (int i = 0; i < size; i++) 
    {
        journal[i].index = i;
        journal[i].value = arr[i];
        journal[i].matched = (arr[i] == target);

        if (journal[i].matched && foundIndex == -1) 
        {
            foundIndex = i;
        }
    }

    return foundIndex;
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
    SearchStep journal[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = linearSearchWithJournal(arr, size, target, journal);
    printf("Search Trace:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("Index %d: Value = %d ", journal[i].index, journal[i].value);

        if (journal[i].matched) 
        {
            printf("[Match]\n");
        } 
        else 
        {
            printf("[No Match]\n");
        }
    }

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
