#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(string s, string raw, vector<string> &wordDict, vector<vector<int>> &DP)
    {
        if (raw == s)
        {
            return true;
        }
        if (raw.size() > s.size())
        {
            return false;
        }
        for (int i = 0; i < wordDict.size(); i++)
        {
            if (DP[raw.size()][i] != -1)
            {
                bool isValid = solve(s, raw + wordDict[i], wordDict);
                if (isValid)
                {
                    return true;
                }
                else
                {
                    DP[raw.size()][i] = 0;
                }
            }
            else
            {
                if (DP[raw.size()][i] == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<vector<int>> DP(s.size(), vector<int>(wordDict.size(), -1));
        bool isValid = solve(s, "", wordDict);
        return isValid;
    }
};
int main()
{
    Solution st;
    vector<string> wordDict = {"cats", "dog", "and", "sand", "cat"};
    string s = "catsandog";
    cout << st.wordBreak(s, wordDict) << endl;
}