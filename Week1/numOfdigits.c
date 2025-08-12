#include <stdio.h>

int main(){

    int num  , n = 0;

    printf("Enter a number");
    scanf("%d",&num);

    int temp = num;
    
    while (temp != 0) {
        temp /= 10;
        n++;
    }

    printf("This is a %d digit number" ,n);

    return 0;
}