#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> output;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                output.push_back(i);
                output.push_back(j);
                return output;
            }
        }
    }
    return output;
}
int main()
{
    vector<int> a = {2, 7, 11, 15};
    vector<int> b = twoSum(a, 9);
    cout << b[0] << " " << b[1] << endl;
    return 0;
}