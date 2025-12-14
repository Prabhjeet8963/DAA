#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int findCelebrity(const vector<vector<int>>& arr) 
{
    int n = (int)arr.size();
    if (n == 0) return -1;

    int a = 0, b = n - 1;
    while (a < b) {
        if (arr[a][b] == 1) 
        {
            // a knows b, a cannot be celebrity
            ++a;
        } 
        else 
        {
            // a does not know b, b cannot be celebrity
            --b;
        }
    }
    int cand = a;
    for (int i = 0; i < n; ++i) 
    {
        if (i == cand) continue;
        if (arr[cand][i] == 1) return -1; // candidate knows someone
        if (arr[i][cand] == 0) return -1; // someone doesn't know candidate
    }
    return cand;
}

int main() 
{
    srand(time(0));
    int n;
    printf("Enter a number: ");
    if (!(cin >> n)) return 0;

    vector<vector<int>> M(n, vector<int>(n));
    int celebrity = -1;  
    while(celebrity < 1)
    {
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            M[i][j] = rand() % 2;
        }
    }
    celebrity = findCelebrity(M);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << M[i][j] << " ";
        }
        cout << '\n';
    }
    cout << celebrity << '\n';
    return 0;
}
