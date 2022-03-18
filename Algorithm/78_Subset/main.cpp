#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    void solve(vector<int> &nums, int position, vector<int> &raw)
    {
        if (position >= nums.size())
        {
            return;
        }
        for (int i = position; i < nums.size(); i++)
        {
            raw.push_back(nums[i]);
            output.push_back(raw);
            solve(nums, i + 1, raw);
            raw.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> raw = {};
        output.push_back(raw);
        solve(nums, 0, raw);
        return output;
    }
};
int main()
{
    Solution st;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> output = st.subsets(nums);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}