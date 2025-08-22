#include <stdio.h>

int main() {
    int arr[] = {1,1,2,2,3,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (n == 0)
    {
        return 0;
    }
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    int newLen = j + 1;
    printf("%d\n", newLen);
    for (int i = 0; i < newLen; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
