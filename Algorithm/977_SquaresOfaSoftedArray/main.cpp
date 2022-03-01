#include <bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] *= nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}
int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    sortedSquares(a);
    return 0;
}