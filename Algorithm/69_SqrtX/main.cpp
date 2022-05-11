#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        int l = 0;
        int r = x;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int square = x / mid;
            if (square == mid && x % mid == 0)
            {
                return mid;
            }
            else if (square > mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if (x / l < l)
        {
            l--;
        }
        return l;
    }
};
int main()
{
    Solution st;
    cout << st.mySqrt(8) << endl;
    return 0;
}