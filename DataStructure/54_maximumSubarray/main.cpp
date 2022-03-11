#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int sum = nums[0];
    int maxSize = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        sum = max(sum + nums[i], nums[i]);
        maxSize = max(sum, maxSize);
    }
    return maxSize;
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