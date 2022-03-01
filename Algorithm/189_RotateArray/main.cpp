#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = k % nums.size(); // if k is greater then size
    if (n > 0)
    {
        reverse(nums.begin(), nums.end());       // reverse full array
        reverse(nums.begin(), nums.begin() + n); // reverse first k elements
        reverse(nums.begin() + n, nums.end());
    }
}
int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);

    cout << rotate(a, 2) << endl;
    return 0;
}