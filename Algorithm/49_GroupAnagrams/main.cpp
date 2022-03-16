#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
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
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}