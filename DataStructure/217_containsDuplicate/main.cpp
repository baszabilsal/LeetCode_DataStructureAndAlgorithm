#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m[nums[i]] > 0)
        {
            return true;
        }
        m[nums[i]] = 1;
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