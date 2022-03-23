#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(string &s, string &p, int m, int n, vector<vector<int>> &memory)
    {
        if (m >= s.size() && n >= p.size())
        {
            return true;
        }
        else if (n >= p.size() && m < s.size())
        {
            return false;
        }
        else if (m >= s.size() && n < p.size())
        {
            for (int k = n; k < p.size(); k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (memory[m][n] != -1)
        {
            return memory[m][n];
        }
        bool isMatch = m < s.size() && n < p.size() && (s[m] == p[n] || p[n] == '?');
        if (isMatch)
        {
            memory[m][n] = solve(s, p, m + 1, n + 1, memory);
            return memory[m][n];
        }
        if (p[n] == '*')
        {
            bool isNext = solve(s, p, m + 1, n, memory);
            if (isNext)
            {
                memory[m][n] = isNext;
                return memory[m][n];
            }
            memory[m][n] = solve(s, p, m, n + 1, memory);
            return memory[m][n];
        }
        memory[m][n] = false;
        return memory[m][n];
    }
    bool isMatch(string s, string p)
    {
        vector<vector<int>> memory(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0, memory);
    }
};
class Solution2
{
public:
    // Recursion=> TLE😥
    // Time and Space: Exponential and O(n+m)stack
    bool func(int i, int j, string &t, string &s)
    {
        // Base case
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (t[k] != '*')
                    return false;
            }
            return true;
        }

        // if they matched
        if (t[i] == s[j] || t[i] == '?')
            return func(i - 1, j - 1, t, s);

        // if They DO NOT match
        if (t[i] == '*')
        {
            return func(i - 1, j, t, s) or func(i, j - 1, t, s);
        }

        return false; // (a == b) no   thats why false;
    }
    bool isMatch(string s, string t)
    {
        return func(t.size() - 1, s.size() - 1, t, s);
    }

    // 1- Based Indexing
    // Memoization=> Acepted🔥
    // Time and Space: O(n*m) and O(n*m) +  O(n+m)stack

    bool func(int i, int j, string &t, string &s, vector<vector<int>> &dp)
    {
        // Base case
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;
        if (j == 0 && i > 0)
        {
            for (int k = 1; k <= i; k++)
            {
                if (t[k - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        // if they matched
        if (t[i - 1] == s[j - 1] || t[i - 1] == '?')
            return dp[i][j] = func(i - 1, j - 1, t, s, dp);

        // if They DO NOT match
        if (t[i - 1] == '*')
        {
            return dp[i][j] = func(i - 1, j, t, s, dp) || func(i, j - 1, t, s, dp);
        }

        return dp[i][j] = false; // (a == b) no thats why false;
    }
    bool isMatch(string s, string t)
    {
        int n = t.size();
        int m = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return func(n, m, t, s, dp);
    }

    // 1- Based Indexing
    // Tabulation=> Accepted🔥
    // Time and Space: O(n*m) and O(n*m)
    bool isMatch(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        // base case - 1
        dp[0][0] = 1;
        // base case - 2
        for (int j = 1; j <= m; j++)
            dp[0][j] = false;
        // base case - 3
        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (t[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // if they matched
                if (t[i - 1] == s[j - 1] || t[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                // if They DO NOT match
                else if (t[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
    // 1- Based Indexing
    // Space Optimization => Accepted🔥
    // Time and Space: O(n*m) and O(2m)
    bool isMatch(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<bool> prev(m + 1, 0), curr(m + 1, 0);

        // base case - 1
        prev[0] = 1;
        // base case - 2
        for (int j = 1; j <= m; j++)
            prev[j] = false;

        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (t[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for (int j = 1; j <= m; j++)
            {
                // if they matched
                if (t[i - 1] == s[j - 1] || t[i - 1] == '?')
                    curr[j] = prev[j - 1];

                // if They DO NOT match
                else if (t[i - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }

                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};
int main()
{
    Solution2 st;
    string s = "aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab";
    string p = "aaab***ba**b*b*aaab*b";
    cout << st.isMatch(s, p) << endl;
}