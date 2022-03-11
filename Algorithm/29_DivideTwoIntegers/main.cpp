#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    return dividend / divisor;
    ;
}
int main()
{
    cout << divide(10, 2) << endl;
}