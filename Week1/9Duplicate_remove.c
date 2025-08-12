// remove all the  
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 4, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int unique[50];  
    int count = 0;

    for(int i = 0; i < size; i++) {
        int m = 1; 

        for (int j = 0; j < count; j++) {

            if (arr[i] == unique[j]) {
                m = 0;  
                break;
            }
        }

        if (m == 1) {
            
            unique[count] = arr[i];
            count++;
            
        }
    }
   
    printf("Unduplicated array \n");
    
    for (int i = 0; i < count; i++) {
        printf("%d ", unique[i]);
    }

    return 0;
}