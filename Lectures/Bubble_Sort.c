/*check digits , 2 for loop ,inside the inner for loop 
Outer loop for passes  
Inner loop for comparison
Swap if the element is greater than the next
int main to take array and display function 
 take nubers as aarays as a = {43,53 , 56 , 54 ,78}
 a function to display the both array the original one and the last one 
**********************************************************************

#include <stdio.h>

void display(int a[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


void Sort(int a[], int size) {
    for(int i = 0; i < size - 1; i++) {                
        for(int j = 0; j < size - i - 1; j++) {  
            if(a[j] > a[j + 1]) {
               int temp = a[j];
               a[j] = a[j+ 1];
               a[j+1] = temp; 
            }
        }
    }
}

int main() {
    int a[] = {43, 78, 53, 56, 54};  
    int size = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    display(a, size);

    Sort(a, size);            

    printf("Sorted array: ");
    display(a, size);

    return 0;
}*/

#include <stdio.h>

void display(int a[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}


void Sort(int a[], int size) {
    for(int i = 0; i < size - 1; i++) { 
        int m = 0;

        for(int j = 0; j < size - i - 1; j++) {  
            if(a[j] > a[j + 1]) {
               int temp = a[j];
               a[j] = a[j+ 1];
               a[j+1] = temp; 
               m = 1;
            }
        }
        if (m == 0){
            printf("The array is already sorted!! \n");
            break;
        }
    }
}

int main() {
    int a[] = {43 ,53 ,54 ,56 ,78 };  
    int size = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    display(a, size);

    Sort(a, size);            

    printf("Sorted array: ");
    display(a, size);

    return 0;
}
