#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size();
    if (nums[l] < nums[r - 1])
    {
        return nums[l];
    }
    while (l < r)
    {
        int med = (l + r) / 2;
        if (nums[med] > nums[0])
        {
            l = med + 1;
        }
        else
        {
            r = med;
        }
    }
    return min(nums[r], nums[l]);
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << endl;
}