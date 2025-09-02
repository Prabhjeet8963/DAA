#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int div = num/2;
    printf("%d %d\n",num,div*2);
    if(num==(div*2))
    {
        printf("Even:");
    }
    else
    {
        printf("Odd:");
    }
}
