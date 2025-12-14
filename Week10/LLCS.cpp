#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// direction codes: 1=diag(match), 2=tie(up+left), 3=up, 4=left
static void dfsAllLCS(int i, int j,
                      const string& s1,
                      const vector<vector<int>>& dir,
                      string& cur,               // building reversed
                      vector<string>& out)       // "normal array" of strings
{
    if (i==0 || j==0) 
    {
        string t = cur;
        reverse(t.begin(), t.end());
        out.push_back(t);
        return;
    }
    int d = dir[i][j];
    if (d == 1) // go diagonal and append char
    {                   
        cur.push_back(s1[i-1]);
        dfsAllLCS(i-1, j-1, s1, dir, cur, out);
        cur.pop_back();
    } 
    else 
    {
        if (d == 3 || d == 2) // up
        {     
            dfsAllLCS(i-1, j, s1, dir, cur, out);
        }
        if (d == 4 || d == 2) // left
        {     
            dfsAllLCS(i, j-1, s1, dir, cur, out);
        }
    }
}

int lcs(const string &s1, const string &s2,vector<vector<int>>& dir)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> len(m+1, vector<int>(n+1, 0));
    dir.assign(m+1, vector<int>(n+1, 0));

    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            if (s1[i-1]==s2[j-1]) 
            {
                len[i][j] = len[i-1][j-1] + 1;
                dir[i][j] = 1;            // diag
            } 
            else 
            {
                if (len[i-1][j] > len[i][j-1]) 
                {
                    len[i][j] = len[i-1][j];
                    dir[i][j] = 3;        // up
                } 
                else if (len[i-1][j] < len[i][j-1]) 
                {
                    len[i][j] = len[i][j-1];
                    dir[i][j] = 4;        // left
                } 
                else 
                {
                    len[i][j] = len[i-1][j]; // tie
                    dir[i][j] = 2;        // tie -> branch
                }
            }
        }
    }
    return len[m][n];
}

int main() {
    string s1 = "ABC";
    string s2 = "CBA";

    vector<vector<int>> direction;
    int L = lcs(s1, s2, direction);

    vector<string> all_lcs;
    string cur;
    dfsAllLCS((int)s1.size(), (int)s2.size(), s1, direction, cur, all_lcs);

    // de-dup and present cleanly
    sort(all_lcs.begin(), all_lcs.end());
    all_lcs.erase(unique(all_lcs.begin(), all_lcs.end()), all_lcs.end());

    cout << "LCS length: " << L << "\n";
    cout << "All LCS (" << all_lcs.size() << "):\n";
    for (int i=0;i<all_lcs.size();i++)
    {
        cout << all_lcs[i] << "\n";
    } 
}
