#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int m, int n, string &text1, string &text2, vector<vector<int>> &DP)
    {
        if (m >= text1.size() || n >= text2.size())
        {
            return 0;
        }
        if (DP[m][n] != -1)
        {
            return DP[m][n];
        }
        bool isMatch = m < text1.size() && n < text2.size() && text1[m] == text2[n];
        if (isMatch)
        {
            DP[m][n] = 1 + solve(m + 1, n + 1, text1, text2, DP);
        }
        int r = solve(m + 1, n, text1, text2, DP);
        int q = solve(m, n + 1, text1, text2, DP);
        if (r > DP[m][n])
        {
            DP[m][n] = r;
        }
        if (q > DP[m][n])
        {
            DP[m][n] = q;
        }
        return DP[m][n];
    }
    int minDistance(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> DP(m + 1, vector<int>(n + 1, -1));
        return (m + n) - (2 * solve(0, 0, text1, text2, DP));
    }
};
int main()
{
    Solution st;
    string text1 = "eatsssss";
    string text2 = "peat";
    cout << st.minDistance(text1, text2) << endl;
}