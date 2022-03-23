#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {

        return output;
    }
};
int main()
{
    Solution st;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> output = st.subsetsWithDup(nums);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}