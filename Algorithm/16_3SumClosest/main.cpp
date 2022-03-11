#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    int output = (nums[0] + nums[1] + nums[2]);
    int dif = abs(target - output);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            int value = nums[i] + nums[l] + nums[r];
            if (dif > abs(target - value))
            {
                dif = abs(target - value);
                output = value;
            }
            if (value < target)
            {
                l++;
            }
            else if (value > target)
            {
                r--;
            }
            else
            {
                return value;
            }
        }
    }
    return output;
}
int main()
{
    vector<int> nums = {1, 1, 1, 0};
    int target = -100;
    cout << threeSumClosest(nums, target) << endl;
}