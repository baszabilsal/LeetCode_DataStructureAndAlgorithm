#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int start = 0;
        int end = 0;
        int sum = 1;
        int total = 0;
        while (end < nums.size())
        {
            sum = sum * nums[end];
            while (sum >= k && start <= end)
            {
                sum = sum / nums[start++];
            }
            total += (end - start) + 1;

            end++;
        }
        return total;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 0;
    Solution st;
    cout << st.numSubarrayProductLessThanK(nums, k) << " " << endl;
}