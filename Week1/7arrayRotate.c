#include <stdio.h>

    /*k to handle cases where k > n
     Copy the last k elements into a temporary array temp
     Shift the remaining elements of the array to the right by k positions
     Copy the saved k elements from the temporary array to the front of the array*/

void rightRotate(int arr[], int n, int k) {
    k = k % n;   

    int temp[k]; 

    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    } //for storing last k elements sepreately

   
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }//Shift to Right

    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
    //Overrides , adds the temp elements
}

int main() {
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k (number of positions to rotate): ");
    scanf("%d", &k);

    rightRotate(arr, n, k);

    printf("Array after right rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}