#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        else if (nums[0] >= (nums.size() - 1))
        {
            return 1;
        }
        else
        {
            int remain = 0;
            int count = 0;
            int i = 0;
            while (i < nums.size())
            {
                remain = nums[i];
                if (i + remain >= (nums.size() - 1))
                {
                    count++;
                    return count;
                }
                int maxRange = 0;
                int position = i;
                while (remain > 0)
                {
                    int totalDistance = remain + nums[i + remain];
                    if (maxRange < totalDistance)
                    {
                        maxRange = totalDistance;
                        position = i + remain;
                    }
                    remain--;
                }
                count++;
                i = position;
            }
            return count;
        }
    }
};
int main()
{
    Solution st;
    vector<int> a = {2, 3, 1, 1, 4};
    cout << st.jump(a) << endl;
}