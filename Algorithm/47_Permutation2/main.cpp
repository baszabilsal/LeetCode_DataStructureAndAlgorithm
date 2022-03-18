#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<vector<int>> set;
    void permutations(vector<int> &nums, int start)
    {
        if (start >= nums.size())
        {
            set.insert(nums);
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[i], nums[start]);
            permutations(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        permutations(nums, 0);
        vector<vector<int>> output(set.begin(), set.end());
        return output;
    }
};
int main()
{
    Solution2 st;
    vector<int> nums = {1, 1, 2, 2};
    vector<vector<int>> b = st.permuteUnique(nums);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}