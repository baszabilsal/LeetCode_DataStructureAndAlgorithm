#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int sum = 1;
        int totalZero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                totalZero++;
            }
            else
            {
                sum *= nums[i];
            }
        }
        if (totalZero >= 2)
        {
            fill(nums.begin(), nums.end(), 0);
            return nums;
        }
        else if (totalZero == 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    nums[i] = sum;
                }
                else
                {
                    nums[i] = 0;
                }
            }
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = sum / nums[i];
            }
        }
        return nums;
    }
    vector<int> productExceptSelf2(vector<int> &nums)
    {
        int front = 1;
        int back = 1;
        int n = nums.size() - 1;
        vector<int> output(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            output[i] *= front;
            front *= nums[i];
            output[n - i] *= back;
            back *= nums[n - i];
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<int> nums = {2, 3, 4, 5, 6};
    nums = st.productExceptSelf2(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
