#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[min] > nums[j])
                {
                    min = j;
                }
            }
            swap(nums[min], nums[i]);
        }
    }
};
int main()
{
    Solution st;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    cout << st.sortColors(nums) << endl;
}