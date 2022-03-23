#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int output = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == output)
            {
                output++;
            }
        }
        return output;
    }
    int firstMissingPositive(vector<int> &nums)
    {
        int output = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int minValue = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[minValue] > nums[j])
                {
                    minValue = j;
                }
            }
            if (nums[minValue] == output)
            {
                output++;
            }
            else if (nums[minValue] > output)
            {
                return output;
            }
            swap(nums[minValue], nums[i]);
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<int> a = {3, 4, -2, 1, 2, 12, -1};
    cout << st.firstMissingPositive(a) << endl;
}