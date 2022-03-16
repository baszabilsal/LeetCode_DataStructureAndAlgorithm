#include <bits/stdc++.h>
using namespace std;
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
    cout << startPosition << endl;
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
}
int main()
{
    vector<int> nums = {7, 5, 6, 4, 3, 2, 1};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}