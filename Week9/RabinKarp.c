#include <stdio.h>
#include <string.h>

#define d 256
#define q 13

int main() 
{
    char text[] = "ABCCDDAEFG";
    char pat[]  = "CDD";

    int n = strlen(text);
    int m = strlen(pat);

    int p = 0, t = 0, h = 1;
    
    // compute h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // compute initial hashes for pattern and first window
    for (int i = 0; i < m; i++) 
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // slide the window
    for (int i = 0; i <= n - m; i++) 
    {
        if (p == t) 
        {
            int match = 1;
            for (int j = 0; j < m; j++) 
            {
                if (text[i + j] != pat[j])
                 match = 0;
            }
            if (match)
                printf("Match at index %d\n", i);
        }

        if (i < n - m) // within bounds
        {
            t = (d * (t - text[i] * h)  + text[i + m]) % q; // (d * (t - old * h) + new) % q
            if (t < 0) 
                t += q;
        }
    }

    return 0;
}
