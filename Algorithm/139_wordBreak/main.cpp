#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(int start, string s, string raw, vector<string> &wordDict, vector<vector<int>> &DP)
    {
        if (raw == s)
        {
            return true;
        }
        if (raw != s.substr(0, raw.size()))
        {
            return false;
        }
        int size = raw.size();
        if (size > s.size())
        {
            return false;
        }
        for (int i = start; i < wordDict.size(); i++)
        {
            if (DP[size][i] == -1)
            {
                bool isValid = solve(start, s, raw + wordDict[i], wordDict, DP);
                if (isValid)
                {
                    return true;
                }
                else
                {
                    DP[size][i] = 0;
                }
            }
            else
            {
                if (DP[size][i] == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<vector<int>> DP(s.size() + 1, vector<int>(wordDict.size() + 1, -1));
        bool isValid = solve(0, s, "", wordDict, DP);
        return isValid;
    }
};
int main()
{
    Solution st;
    vector<string> wordDict = {"a", "abc", "b", "cd"};
    string s = "aabcde";
    cout << st.wordBreak(s, wordDict) << endl;
}