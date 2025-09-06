#include <stdio.h>

void merge(int arr[],int left,int mid,int right)
{
    int leftN = mid-left+1; //+1 for 0th element
    int rightN = right-mid;

    int leftArray[leftN];
    int rightArray[rightN];
    for(int i=0;i<leftN;i++)
    {
        leftArray[i]=arr[left+i];
    }
    for(int i=0;i<rightN;i++)
    {
        rightArray[i]=arr[mid+1+i];
    }

    int leftCounter = 0;
    int rightCounter = 0;
    int i = left;

    while (leftCounter<leftN && rightCounter<rightN)
    {
        if(leftArray[leftCounter] < rightArray[rightCounter])
        {
            arr[i] = leftArray[leftCounter];
            leftCounter++;
        }
        else
        {
            arr[i] = rightArray[rightCounter];
            rightCounter++;
        }
        i++;
    }

    while(leftCounter<leftN)
    {
        arr[i]=leftArray[leftCounter];
        leftCounter++;
        i++;
    }
    while(rightCounter<rightN)
    {
        arr[i]=rightArray[rightCounter];
        rightCounter++;
        i++;
    }
}

void mergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid = (left + right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

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
    
    //check if sorted already
    int sorted = 0;
    for(int i=0;i<len-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            sorted = 0;
            break;
        }
        if(arr[i] <= arr[i+1])
        {
            sorted = 1;
        }
    }

    if(sorted==1) //Already sorted
    {
        for(int i=0;i<len;i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nAlready sorted\n");
        return 0;
    }

    printf("before sorting\n");
    for(int i=0;i<len;i++)
    {
        printf("%d ", arr[i]);
    }

    //sorting
    mergeSort(arr,0,len-1);

    printf("\nafter sorting\n");
    for(int i=0;i<len;i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
