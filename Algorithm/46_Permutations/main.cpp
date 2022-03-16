#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    void nextPermutation(vector<int> &nums)
    {
        int startPosition = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                startPosition = i;
                break;
            }
        }
        if (startPosition == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[startPosition] < nums[i])
                {
                    swap(nums[startPosition], nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + startPosition + 1, nums.end());
        }
        output.push_back(nums);
    }
    int nflak(int n)
    {
        int sum = 1;
        for (int i = n; i > 0; i--)
        {
            sum *= i;
        }
        return sum;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        int s = nums.size();
        output.push_back(nums);
        s = nflak(s) - 1;
        while (s--)
        {
            nextPermutation(nums);
        }
        return output;
    }
    void permutations(vector<vector<int>> &ans, vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            permutations(ans, nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute2(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permutations(ans, nums, 0);
        return ans;
    }
};

int main()
{
    Solution st;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> b = st.permute2(nums);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}