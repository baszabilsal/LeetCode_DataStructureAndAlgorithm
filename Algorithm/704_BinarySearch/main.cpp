#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();
    while (l < r)
    {
        int med = l + r / 2;
        if (nums[med] == target)
        {
            return med;
        }
        else if (nums[med] > target)
        {
            r = med;
        }
        else
        {
            l = med + 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    cout << search(a, 2) << endl;
    return 0;
}