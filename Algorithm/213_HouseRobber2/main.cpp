#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int robHouse(vector<int> nums, int start, int end)
    {
        int maxMoney = 0;
        for (int i = start; i < end; i++)
        {
            int house1 = 0;
            if (i - 2 >= start)
            {
                house1 = nums[i - 2];
            }
            int house2 = 0;
            if (i - 3 >= start)
            {
                house2 = nums[i - 3];
            }
            nums[i] += max(house1, house2);
            maxMoney = max(maxMoney, nums[i]);
        }
        return maxMoney;
    }
    int robHouseRecursive(vector<int> &nums, int start, int end, int running, int maxMoney)
    {
        if (running >= end)
        {
            return maxMoney;
        }
        int house1 = 0;
        if (running - 2 >= start)
        {
            house1 = nums[running - 2];
        }
        int house2 = 0;
        if (running - 3 >= start)
        {
            house2 = nums[running - 3];
        }
        nums[running] += max(house1, house2);
        maxMoney = max(maxMoney, nums[running]);
        return robHouseRecursive(nums, start, end, running + 1, maxMoney);
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        else
        {
            vector<int> nums2 = nums;
            int house1 = robHouseRecursive(nums2, 0, nums2.size() - 1, 0, 0);
            int house2 = robHouseRecursive(nums, 1, nums2.size(), 1, 0);
            return max(house1, house2);
        }
    }
};
int main()
{
    Solution st;
    vector<int> ar = {200, 3, 140, 20, 10};
    cout << st.rob(ar) << endl;
}