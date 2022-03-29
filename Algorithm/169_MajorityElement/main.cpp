#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > n / 2)
            {
                return nums[i];
            }
        }
        return 0;
    }
};
int main()
{
    Solution st;
    vector<int> nums = {5, 2, 1, 2, 1, 2};
    cout << st.majorityElement(nums) << endl;
}