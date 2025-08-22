#include <stdio.h>

int main() {
    int arr[] = {7, 1, 5, 5, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int first = -1000000, second = -1000000;
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } 
        else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == -1000000){
        printf("No second largest");
    } 
    else {
        printf("%d", second);
    }
    return 0;
}
