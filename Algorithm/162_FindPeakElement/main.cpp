#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int l = 0;
    int r = nums.size();
    while (l < r)
    {
        int med = (l + r) / 2;
        int medL = med - 1;
        int medR = med + 1;
        if (medL < 0 && medR >= nums.size() ||
            medL < 0 && nums[med] > nums[medR] ||
            medR >= nums.size() && nums[med] > nums[medL] ||
            nums[med] > nums[medL] && nums[med] > nums[medR])
        {
            return med;
        }
        else if (nums[med] >= nums[medL])
        {
            l = med + 1;
        }
        else
        {
            r = med;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 3, 5, 5, 5, 6, 4};
    cout << findPeakElement(nums) << endl;
}