#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res ^= nums[i];
        cout << res << endl;
    }
    return res;
}
int main()
{
    vector<int> nums = {5, 2, 1, 2, 1};
    cout << singleNumber(nums) << endl;
}