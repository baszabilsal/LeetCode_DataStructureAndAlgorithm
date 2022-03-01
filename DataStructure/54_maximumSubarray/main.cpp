#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int sum = nums[0];
    int maxEnd = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        sum += nums[i];
        if (nums[i] > sum)
        {
            sum = nums[i];
        }
        if (sum > maxEnd)
        {
            maxEnd = sum;
        }
    }
    return maxEnd;
}
int main()
{
    vector<int> a;
    a.push_back(-2);
    a.push_back(3);
    a.push_back(-4);

    cout << maxSubArray(a) << endl;
    return 0;
}