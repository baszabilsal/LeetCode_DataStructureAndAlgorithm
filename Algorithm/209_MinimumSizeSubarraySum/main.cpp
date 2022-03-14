#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;
        int end = 0;
        int minSize = nums.size() + 1;
        int sum = 0;
        while (end < nums.size())
        {
            sum += nums[end];
            while (sum >= target && start <= end)
            {
                minSize = min(minSize, (end - start) + 1);
                if (minSize == 1)
                {
                    return 1;
                }
                sum -= nums[start++];
            }
            end++;
        }
        return minSize != nums.size() + 1 ? minSize : 0;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 10;
    Solution st;
    cout << st.minSubArrayLen(k, nums) << " " << endl;
}