#include <iostream>
using namespace std;

int knapsackRec(int n, int val[], int wt[], int cap, int i) 
{
    if (n == i || cap <= 0)
        return 0;

    int valueIn = 0, valueEx = 0;
    
    if(wt[i] <= cap)
    {
        valueIn = knapsackRec(n, val, wt, cap - wt[i], i+1) + val[i];

        valueEx = knapsackRec(n, val, wt, cap, i+1);
        return max(valueIn, valueEx);
    }
    else
    {
        valueEx = knapsackRec(n, val, wt, cap, i+1);
        return valueEx;
    }
}

int knapsack(int n, int val[], int wt[], int cap) 
{    
    return knapsackRec(n, val, wt , cap, 0);
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
    cout << "Maximum profit: " << knapsack(n, val, wt, cap) << endl;

    return 0;
}
