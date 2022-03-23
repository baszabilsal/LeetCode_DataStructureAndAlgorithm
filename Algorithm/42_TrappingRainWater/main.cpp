#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];
        int output = 0;
        while (l < r)
        {
            if (maxL > maxR)
            {
                maxR = max(maxR, height[--r]);
                output += maxR - height[r];
            }
            else
            {
                maxL = max(maxL, height[++l]);
                output += maxL - height[l];
            }
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << st.trap(v) << endl;
}