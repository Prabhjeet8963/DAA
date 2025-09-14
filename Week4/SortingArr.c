#include <stdio.h>

int main()
{
    int len;
    printf("Enter the size of the arrays:");
    scanf("%d",&len);
    int key[len];
    int value[len];
    for(int i=0;i<len;i++)
    {
        printf("Enter key:");
        scanf("%d",&key[i]);
        printf("Enter value for that key:");
        scanf("%d",&value[i]);
    }
    printf("Before Sorting:\n");
    for(int i=0;i<len;i++)
    {
        printf("%d:%d ",key[i],value[i]);
    }
    //sort keys and their values
    for(int j=0;j<len-1;j++)
    {
    int min=key[j];
    int min_index=j;
    for(int i=j+1;i<len;i++)
    {
        if(key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
        continue;
    }
    key[min_index]=key[j];
    key[j]=min;
    int temp = value[min_index];
    value[min_index] = value[j];
    value[j] = temp; 
    }
    printf("\nAfter Sorting Keys:\n");
    for(int i=0;i<len;i++)
    {
        printf("%d:%d ",key[i],value[i]);
    }
}
