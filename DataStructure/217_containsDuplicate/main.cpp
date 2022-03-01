#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != temp || i == 0)
        {
            temp = nums[i];
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> a;
    a.push_back(-2);
    a.push_back(3);
    a.push_back(-4);

    cout << containsDuplicate(a) ? 1 : 0 << endl;
    return 0;
}