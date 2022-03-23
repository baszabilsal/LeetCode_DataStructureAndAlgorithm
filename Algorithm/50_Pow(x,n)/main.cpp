#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double solve(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        double res = 0;
        int nMOd = 0;
        if (n < 0)
        {
            x = 1 / x;
            res = solve(x * x, abs(n / 2));
            nMOd = abs(n % 2);
        }
        else
        {
            res = solve(x * x, n / 2);
            nMOd = n % 2;
        }
        if (nMOd == 1)
        {
            return res * x;
        }
        return res;
    }
    double myPow(double x, int n)
    {
        return solve(x, n);
    }
};
int main()
{
    Solution st;
    cout << st.myPow(2, -10) << endl;
}