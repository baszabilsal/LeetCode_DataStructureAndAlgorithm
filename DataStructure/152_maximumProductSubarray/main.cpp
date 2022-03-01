#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums);
int main()
{
    vector<int> a;
    a.push_back(-2);
    a.push_back(3);
    a.push_back(-4);

    cout << maxProduct(a) << endl;
    return 0;
}
int maxProduct(vector<int> &nums)
{
    int sum = nums[0];
    int sum2 = nums[0];
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        sum *= nums[i];
        sum2 *= nums[i];
        if (sum > sum2)
        {
            sum2 = sum2 < nums[i] ? sum2 : nums[i];
            sum = sum > nums[i] ? sum : nums[i];
        }
        else
        {
            int temp = sum2;
            sum2 = sum < nums[i] ? sum : nums[i];
            sum = temp > nums[i] ? temp : nums[i];
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}