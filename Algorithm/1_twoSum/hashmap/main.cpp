#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0)
        {
            for (int j = 0; j < hash.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {j, i};
                }
            }
        }
        hash.push_back(target - nums[i]);
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