#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();

    // Create a 2D DP array to store the minimum multiplication costs
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP array.
    for (int len = 2; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++)
            {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // The minimum cost is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter how many matrices you want: ";
    cin >> n;
    for(int i=0;i<=n;i++)
    {
        int input;
        cout << "Enter dimension of Matrix: ";
        cin >> input;
        arr.push_back(input);
    }
    cout << "Minimum number of multiplication: " << matrixMultiplication(arr);
    return 0;
}
