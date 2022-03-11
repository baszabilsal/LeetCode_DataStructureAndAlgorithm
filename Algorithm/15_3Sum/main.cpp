#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> output;
    if (nums.size() > 2)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            while (i != 0 && nums[i - 1] == nums[i])
                i++;
            cout << i << endl;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    cout << "in" << endl;
                    vector<int> a = {nums[i], nums[l], nums[r]};
                    output.push_back(a);
                    while (l < r && nums[r - 1] == nums[r])
                        r--;
                    while (l < r && l > 0 && nums[l] == nums[l + 1])
                        l++;
                }
                if (nums[i] + nums[l] + nums[r] < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }
    return output;
}
int main()
{
    vector<int> nums = {-2, 0, 0, 2, 2};
    vector<vector<int>> output = threeSum(nums);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << output[i][j] << ",";
        }
        cout << endl;
    }
}