#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n)
{
    if (n > 2)
    {
        int step1 = 1;
        int step2 = 2;
        int temp = 0;
        for (int i = 3; i <= n; i++)
        {
            temp = step1;
            step1 = step2;
            step2 += temp;
        }
        return step2;
    }
    else
    {
        return n;
    }
}
int main()
{

    cout << climbStairs(10) << endl;
}