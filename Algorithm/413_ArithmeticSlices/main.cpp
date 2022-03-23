#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int DIF = 5000;
    int solve(vector<int> &nums, vector<int> &DP, vector<bool> &VIS, int start)
    {
        if (start < 0)
        {
            return 0;
        }
        if (VIS[start])
        {
            return DP[start];
        }
        int ans = 0;
        int dif = 0;
        if (start >= 1)
        {
            dif = nums[start] - nums[start - 1];
        }
        for (int i = start; i > 0; i--)
        {
            if (nums[i] - nums[i - 1] == dif)
            {
                if (i <= start - 1)
                {
                    ans++;
                }
            }
            else
            {
                break;
            }
        }
        ans += solve(nums, DP, VIS, start - 1);
        VIS[start] = true;
        return DP[start] = ans;
    }
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> DP(N, 0);
        vector<bool> VIS(N, false);
        return solve(nums, DP, VIS, N - 1);
    }
};
int main()
{
    Solution st;
    vector<int> a = {1, 10, 19, 28, 37};
    cout << st.numberOfArithmeticSlices(a) << endl;
}