#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> output;
        if (nums.size() > 2)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++)
            {
                while (i != 0 && i < nums.size() - 2 && nums[i] == nums[i - 1])
                {
                    i++;
                }
                int l = i + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum == 0)
                    {
                        output.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1])
                        {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r + 1])
                        {
                            r--;
                        }
                    }
                    else if (sum < 0)
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
};
int main()
{
    Solution st;
    vector<int> nums = {-2, 0, 0, 2, 2};
    vector<vector<int>> output = st.threeSum(nums);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << output[i][j] << ",";
        }
        cout << endl;
    }
}