#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> permute(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    do
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            cout << nums[i];
        }
        cout << endl;
        ans.push_back(v);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> b = permute(nums);
}