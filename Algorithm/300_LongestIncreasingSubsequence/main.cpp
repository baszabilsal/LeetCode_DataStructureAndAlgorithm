#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int output = 1;
        int n = nums.size();
        vector<int> DP(n + 1, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (DP[j] + 1 > DP[i])
                    {
                        DP[i] = DP[j] + 1;
                    }
                }
            }
            output = max(output, DP[i]);
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<int> s = {10, 9, 2, 5, 3, 7, 101, 1, 103, 2};
    cout << st.lengthOfLIS(s) << endl;
}