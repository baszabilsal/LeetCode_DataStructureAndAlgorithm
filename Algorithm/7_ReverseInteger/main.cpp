#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    bool isNegative = x < 0;
    int output = 0;
    try
    {
        int real = abs(x);
        string s = to_string(real);
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }

        output = stoi(s);
    }
    catch (const std::exception &e)
    {
        output = 0;
    }
    return output * (isNegative ? -1 : 1);
}
int reverse2(int x)
{
    bool isNegative = x < 0;
    int output = 0;
    try
    {
        int real = abs(x);
        string s = to_string(real);
        int l = 0;
        int r = s.size() - 1;
        while (l <= r)
        {
            int intR = s[r] - '0';
            int intL = s[l] - '0';

            if (l == r)
            {
                if ((intR * pow(10, r)) + output > INT_MAX)
                {
                    return 0;
                }
                output += (intR * pow(10, r));
            }
            else
            {
                if ((intR * pow(10, r)) + (intL * pow(10, l)) + output > INT_MAX)
                {
                    return 0;
                }
                output += ((intR * pow(10, r)) + (intL * pow(10, l)));
            }
            l++;
            r--;
        }
    }
    catch (const std::exception &e)
    {
        output = 0;
    }
    return output * (isNegative ? -1 : 1);
}
int main()
{
    int s = -1563847412;
    cout << reverse2(s) << endl;
    return 0;
}