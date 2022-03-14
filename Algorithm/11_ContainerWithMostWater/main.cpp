#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    int maxSize = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r)
    {
        int minHeight = min(height[l], height[r]);
        maxSize = max(maxSize, (minHeight * (r - l)));
        if (height[l] > height[r])
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return maxSize;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}