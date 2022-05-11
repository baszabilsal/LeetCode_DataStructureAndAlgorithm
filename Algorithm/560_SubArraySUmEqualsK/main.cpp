#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int sum = 0;
        int count = 0;
        m[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int find = sum - k;
            if (m.find(find) != m.end())
            {
                count += m[find];
            }
            m[sum]++;
        }
        return count;
    }
};
int main()
{
    vector<int> nums = {1, 1, 0, 0, 3, 4};
    Solution st;
    cout << st.subarraySum(nums, 7) << endl;
}