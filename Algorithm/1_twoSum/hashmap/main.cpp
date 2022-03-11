#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums[i]) != m.end())
        {
            return {m[nums[i]], i};
        }
        m[target - nums[i]] = i;
    }
    return {-1, -1};
}
int main()
{
    vector<int> a = {2, 7, 11, 15};
    vector<int> b = twoSum(a, 9);
    cout << b[0] << " " << b[1] << endl;
    return 0;
}