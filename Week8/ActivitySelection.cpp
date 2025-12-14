#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort based on finish times
void sortArrays(vector<int> &start, vector<int> &finish)
{
    int n = finish.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (finish[j] < finish[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap finish times
        int temp = finish[i];
        finish[i] = finish[minIndex];
        finish[minIndex] = temp;

        // Swap corresponding start times
        temp = start[i];
        start[i] = start[minIndex];
        start[minIndex] = temp;
    }
}

int activitySelection(vector<int> &start, vector<int> &finish)
{
    int n = start.size();

    // Sort activities by finish time
    sortArrays(start, finish);

    // The first activity always gets selected
    int count = 1;
    int lastFinish = finish[0];

    for (int i = 1; i < n; i++)
    {
        // If the current activity starts after the last one finishes
        if (start[i] > lastFinish)
        {
            count++;
            lastFinish = finish[i];
        }
    }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    int result = activitySelection(start, finish);
    cout << "Maximum number of activities: " << result << endl;

    return 0;
}
