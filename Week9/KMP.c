#include <stdio.h>
#include <string.h>

void computeLPS(char pat[], int m, int lps[]) 
{
    
    int len = 0;      // length of current longest prefix-suffix
    lps[0] = 0;       // first value is always 0

    for (int i = 1; i < m; i++) 
    {
        // go back until we either match or become 0
        while (len > 0 && pat[i] != pat[len]) 
        {
            len = lps[len - 1];
        }

        // if characters match, extend current prefix-suffix
        if (pat[i] == pat[len]) 
        {
            len++;
        }

        lps[i] = len;
    }
}


int main() {
    char text[] = "BABABABABCABABCABAB";
    char pat[]  = "ABABCABAB";

    int n = strlen(text);
    int m = strlen(pat);

    int lps[m];
    computeLPS(pat, m, lps);

    int i = 0; // text index
    int j = 0; // pattern index
    int found = 0;

    while (i < n) 
    {
        if (text[i] == pat[j]) 
        {
            i++;
            j++;
        }

        if (j == m) 
        {
            printf("Match at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } 
        else if (i < n && text[i] != pat[j]) 
        {
            if (j != 0) 
            {
                j = lps[j - 1];
            } 
            else 
            {
                i++;
            }
        }
    }

    if (!found) 
    {
        printf("No match found\n");
    }

    return 0;
}
