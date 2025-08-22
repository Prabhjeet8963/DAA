//finding the gcd using an array
//This is the optimized code!
#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int g = arr[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, arr[i]);
    }

    int l = arr[0];
    for (int i = 1; i < n; i++) {
        l = (l * arr[i]) / gcd(l, arr[i]);
    }

    printf("GCD: %d\n", g);
    printf("LCM: %d\n", l);

    return 0;
}
