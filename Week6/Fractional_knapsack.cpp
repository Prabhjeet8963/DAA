#include <iostream>
#include <algorithm>
using namespace std;

double fractionalKnapsack(int val[], int wt[], int n, int capacity) 
{
    double ratio[n];
    for (int i = 0; i < n; i++) 
    {
        ratio[i] = (double)val[i] / wt[i];
    }

    // Sort items by ratio in descending order using selection sort
    for (int i = 0; i < n - 1; i++) 
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (ratio[j] > ratio[maxIndex])
            {
                maxIndex = j;
            }
        }

        swap(ratio[i], ratio[maxIndex]);
        swap(val[i], val[maxIndex]);
        swap(wt[i], wt[maxIndex]);
    }

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) 
    {
        if (wt[i] <= remainingCapacity) 
        {
            totalValue += val[i];
            remainingCapacity -= wt[i];
        } 
        else 
        {
            totalValue += ratio[i] * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

void displayArray(int arr[], int n)
{   
    cout << "[ ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main() 
{
    int val[] = {3, 4, 5, 6};
    int wt[] = {2, 3, 4, 5};
    int cap = 10;
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Values:";
    displayArray(val, n);
    cout << "Weight:";
    displayArray(wt, n);
    cout << "Capacity: " << cap << endl; 
    cout << "Maximum value = " << fractionalKnapsack(val, wt, n, cap) << endl;

    return 0;
}
