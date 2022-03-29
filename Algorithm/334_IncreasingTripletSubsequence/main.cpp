#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min1 = nums[0];
        bool isSetMin2 = false;
        int min2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (min1 < nums[i])
            {
                if (isSetMin2 && min2 < nums[i])
                {
                    return true;
                }
                else if (!isSetMin2)
                {
                    min2 = nums[i];
                }
                min2 = nums[i];
                isSetMin2 = true;
            }
            else
            {
                min1 = nums[i];
            }
        }
        return false;
    }
};
int main()
{
    Solution st;
    vector<int> nums = {2, 5, 4, 1, 5};
    cout << st.increasingTriplet(nums) << " " << endl;
}
