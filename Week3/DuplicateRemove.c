#include <stdio.h>

int main()
{
    int len;
    printf("Enter the size of array:");
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++)
    {
        printf("Enter a number:");
        scanf("%d",&arr[i]);
    }

    //check if sorted
    int sorted = 1;
    for(int i=0;i<len-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            sorted = 0;
            break;
        }
    }
    if(sorted==0)
    {
        printf("Array not sorted,Exit");
        return 1;
    }

    int currNum = arr[0];
    int newLen = len;
    for(int i=1;i<len;i++)
    {   
        if(arr[i]==currNum)
        {
            newLen--;
            arr[i] = currNum-1;
        }
        else
        {
            currNum = arr[i];
        }
    }

    int newArr[newLen];
    int newIndex = 0;
    currNum = arr[0];
    for(int i=0;i<len;i++)
    {
        if(arr[i]<currNum)
        {
            continue;
        }
        else
        {
            newArr[newIndex] = arr[i];
            newIndex++;
            currNum = arr[i];
        }
    }
    printf("\nNew Length = %d\nNew Array = ",newLen);
    for(int i=0;i<newLen;i++)
    {
        printf("%d ",newArr[i]);
    }
    
    currNum = arr[0];
    for(int i=1;i<len;i++)
    {
        if(arr[i]<currNum)
        {
            arr[i]++;
        }
        else
        {
            currNum = arr[i];
        }
    }
    printf("\nOriginal Array = ");
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
}
