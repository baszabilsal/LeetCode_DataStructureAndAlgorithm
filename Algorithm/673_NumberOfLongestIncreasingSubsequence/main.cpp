#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int ans = 1;
        int n = nums.size();
        vector<int> DP(n + 1, 1);
        vector<int> count(n + 1, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (DP[j] + 1 > DP[i])
                    {
                        DP[i] = DP[j] + 1;
                        count[i] = count[j];
                    }
                    else if (DP[j] + 1 == DP[i])
                    {
                        count[i] += count[j];
                    }
                }
                ans = max(ans, DP[i]);
            }
        }
        int output = 0;
        for (int i = 0; i < n; i++)
        {
            if (DP[i] == ans)
            {
                output += count[i];
            }
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<int> s = {2, 2, 2, 2, 2};
    cout << st.findNumberOfLIS(s) << endl;
}