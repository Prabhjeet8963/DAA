#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "listen";
    char s2[] = "silent";

    if (strlen(s1) != strlen(s2)) {
        printf("false\n");
        return 0;
    }

    int freq[256] = {0};

    for (int i = 0; s1[i] != '\0'; i++) {
        freq[(unsigned char)s1[i]]++;
        freq[(unsigned char)s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("false\n");
            return 0;
        }
    }

    printf("true\n");
    return 0;
}