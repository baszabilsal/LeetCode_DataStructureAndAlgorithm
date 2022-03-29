#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() > 1)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 1; i = i + 2)
            {
                if (nums[i] != nums[i + 1])
                {
                    return nums[i];
                }
            }
            return nums[nums.size() - 1];
        }
        else
        {
            return nums[0];
        }
    }
    int singleNumber2(vector<int> &nums)
    {
        if (nums.size() > 1)
        {
            int output = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                output ^= nums[i];
            }
            return output;
        }
        else
        {
            return nums[0];
        }
    }
};
int main()
{
    Solution st;
    vector<int> nums = {5, 2, 1, 2, 1};
    cout << st.singleNumber(nums) << endl;
}