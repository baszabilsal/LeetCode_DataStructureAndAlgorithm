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
            if (i != position && nums[i] == nums[i - 1])
            {
                continue;
            }
            raw.push_back(nums[i]);
            output.push_back(raw);
            solve(nums, i + 1, raw);
            raw.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> raw = {};
        output.push_back(raw);
        solve(nums, 0, raw);
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