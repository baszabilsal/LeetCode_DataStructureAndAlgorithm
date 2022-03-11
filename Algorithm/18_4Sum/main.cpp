#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> output;
    if (nums.size() > 3)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            while (i != 0 && i < nums.size() - 3 && nums[i - 1] == nums[i])
            {
                i++;
            }
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                while (j != i + 1 && j < nums.size() - 2 && nums[j - 1] == nums[j])
                {
                    j++;
                }
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    long sum = nums[i];
                    sum += nums[j];
                    sum += nums[l];
                    sum += nums[r];
                    if (sum == target)
                    {
                        output.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[r - 1] == nums[r])
                        {
                            r--;
                        }
                        while (l < r && nums[l + 1] == nums[l])
                        {
                            l++;
                        }
                    }
                    if (sum > target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
    }
    return output;
}
int main()
{
    vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
    int target = 0;
    vector<vector<int>> output = fourSum(nums, target);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << output[i][j] << ",";
        }
        cout << endl;
    }
}