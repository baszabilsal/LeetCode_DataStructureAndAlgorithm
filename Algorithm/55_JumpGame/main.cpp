#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(vector<int> &nums, int start)
    {
        if (start >= nums.size() - 1)
        {
            return true;
        }
        if (nums[start] > 0)
        {
            int nextPosition = 0;
            int maxMove = 0;
            int maxSize = (nums[start] + start) > nums.size() - 1 ? nums.size() - 1 : (nums[start] + start);
            for (int i = start + 1; i <= maxSize; i++)
            {
                int move = nums[i] + (i - start);
                if (i == start + 1)
                {
                    maxMove = move;
                    nextPosition = i;
                }
                else
                {
                    if (maxMove < move)
                    {
                        maxMove = move;
                        nextPosition = i;
                    }
                }
            }
            return solve(nums, nextPosition);
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        return solve(nums, 0);
    }
};
int main()
{
    Solution st;
    vector<int> ar = {2, 3, 1, 1, 4};
    cout << st.canJump(ar) << endl;
}