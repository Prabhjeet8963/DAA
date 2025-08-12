//Convert all lower case character to upper case 

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "hello";
    int i = 0;

    while (str[i] != '\0') {
        str[i] = toupper(str[i]); 
        i++;
    }

    printf("Uppercase: %s\n", str);
    return 0;
}