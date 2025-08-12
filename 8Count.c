#include <stdio.h>

int main() {

    char str[] = "Count words ";
    int i = 0;
    int count = 0;
    int Word = 0;


    while (str[i] != '\0') {
        if (str[i] != ' ' && Word == 0) {
            count++;        
            Word = 1;     
        }
        
        else if (str[i] == ' ') {
            Word = 0;     
        }
        i++;
    }

    printf("Word count: %d \n", count);
    return 0;
}