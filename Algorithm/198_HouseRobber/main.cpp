#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    int house3 = 0;
    int house2 = 0;
    int house1 = 0;
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        temp = max(house2, house1) + nums[i];
        house1 = house2;
        house2 = house3;
        house3 = temp;
    }
    return max(house3, house2);
}
int main()
{
    vector<int> a = {1, 23, 4, 5, 6, 7, 78, 8};
    cout << rob(a) << endl;
}