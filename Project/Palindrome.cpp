#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

void precomputePal(char *s, bool pal[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        pal[i][i] = true;
    }
    for (int len = 2; len <= n; len++) {
        for (int start = 0; start + len <= n; start++) {
            int end = start + len - 1;
            if (s[start] != s[end]) {
                pal[start][end] = false;
            } else {
                if (len == 2) {
                    pal[start][end] = true;
                } else {
                    pal[start][end] = pal[start + 1][end - 1];
                }
            }
        }
    }
}

void solve(char *s, int start, char partition[][MAX], int index, bool pal[MAX][MAX], int n) {
    if (start == n) {
        for (int i = 0; i < index; i++) {
            printf("%s ", partition[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < n; i++) {
        if (pal[start][i]) {
            int k = 0;
            for (int j = start; j <= i; j++) {
                partition[index][k++] = s[j];
            }
            partition[index][k] = '\0';
            solve(s, i + 1, partition, index + 1, pal, n);
        }
    }
}

int main() {
    char s[MAX];
    bool pal[MAX][MAX] = {false};
    char partition[MAX][MAX];
    
    printf("Enter string: ");
    scanf("%s", s);
    
    int n = strlen(s);
    precomputePal(s, pal, n);
    
    printf("\nAll Palindrome Partitions:\n");
    solve(s, 0, partition, 0, pal, n);
    
    return 0;
}