#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int n, int start, vector<int> &DP)
    {
        if (start > n)
        {
            return;
        }
        DP[start] = start;
        for (int j = 1; j <= start; j++)
        {
            DP[start] = max((start - j) * j, DP[start]);
            DP[start] = max(DP[start], DP[j] * (start - j));
        }
        solve(n, start + 1, DP);
    }
    int integerBreak(int n)
    {
        vector<int> DP(n + 1, 0);
        solve(n, 1, DP);
        return DP[n];
    }
};
int main()
{
    Solution st;
    cout << st.integerBreak(5) << " " << endl;
}
