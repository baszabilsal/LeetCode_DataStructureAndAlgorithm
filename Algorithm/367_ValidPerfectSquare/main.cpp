#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 0 || num == 1)
        {
            return true;
        }
        int l = 0;
        int r = num;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int square = num / mid;
            if (square == mid && num % mid == 0)
            {
                return true;
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
        return false;
    }
};
int main()
{
    Solution st;
    cout << st.isPerfectSquare(15) << endl;
    return 0;
}