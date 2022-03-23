#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> output;
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.size() == 1)
        {
            output.push_back(strs);
        }
        else
        {
            unordered_map<string, vector<string>> m;
            for (int i = 0; i < strs.size(); i++)
            {
                string s = strs[i];
                sort(strs[i].begin(), strs[i].end());
                m[strs[i]].push_back(s);
            }
            for (auto const &imap : m)
            {
                output.push_back(imap.second);
            }
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<string> b = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> output = st.groupAnagrams(b);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[j].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}