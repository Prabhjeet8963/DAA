#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start,end;
    double cpu_time_used;
    start = clock();

    int NumDigits=0;
    int range = 10000000;
    for(int num=1;num<=range;num++)
    {
        for(int i=num;i>0;)
        {
            i = i/10;
            NumDigits++;
        }
        int sum=0;
        for(int i=num;i>0;)
        {
            int power = NumDigits;
            int digit = i%10;
            int res = 1;
            while(power>0)
            {
                if(power%2==1)
                {
                    res = res * digit;
                }
                power = power/2;
                digit = digit*digit;
            }
            sum = sum + res;
            i = i/10;
        }
        if(sum == num)
        {
            printf("The number %d is armstrong\n",num);
        }
        NumDigits=0;
    }
    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    printf("Program took %f seconds to execute.\n",cpu_time_used);
}
