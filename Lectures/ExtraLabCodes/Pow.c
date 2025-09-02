#include <stdio.h>
#include <math.h>

// Method 1: Divide until 1
float div(int n)
{
    if (n <= 0)
    {
        return 0.0;
    }

    while (n % 2 == 0)
    {
        n /= 2;
    }

    return (n == 1) ? 1.0 : 0.0;
}

// Method 2: Count 1s in binary
float bits(int n)
{
    if (n <= 0)
    {
        return 0.0;
    }

    int c = 0;
    while (n)
    {
        c += n & 1;
        n >>= 1;
    }

    return (c == 1) ? 1.0 : 0.0;
}

#include <math.h>

// Method 3: Use log2 to check if result is an integer
float logg(int n)
{
    if (n <= 0)
    {
        return 0.0;
    }

    double res = log2(n);
    if (floor(res) == res)
    {
        return 1.0;
    }

    return 0.0;
}

// Method 4: Bitwise trick
float fast(int n)
{
    if (n > 0 && (n & (n - 1)) == 0)
    {
        return 1.0;
    }

    return 0.0;
}

int main()
{
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    printf("\n--- Power of Two Check ---\n");
    printf("Method 1 (Divide): %s\n", div(x) == 1.0 ? "YES" : "NO");
    printf("Method 2 (Bit Count): %s\n", bits(x) == 1.0 ? "YES" : "NO");
    printf("Method 3 (Log Check): %s\n", logg(x) == 1.0 ? "YES" : "NO");
    printf("Method 4 (Bitwise Trick): %s\n", fast(x) == 1.0 ? "YES" : "NO");

    return 0;
}
