#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int maxSize = 0;
    while (l < r)
    {
        maxSize = max(maxSize, ((r - l) * min(height[r], height[l])));
        if (height[r] > height[l])
        {
            l++;
        }
        else
        {
            r--;
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