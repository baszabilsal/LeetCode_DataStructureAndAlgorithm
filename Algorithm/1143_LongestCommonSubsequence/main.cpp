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
        DP[m][n] = max(DP[m][n], r);
        DP[m][n] = max(DP[m][n], q);
        return DP[m][n];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> DP(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return solve(0, 0, text1, text2, DP);
    }
};
int main()
{
    Solution st;
    string text1 = "abcdea";
    string text2 = "aeca";
    cout << st.longestCommonSubsequence(text1, text2) << endl;
}