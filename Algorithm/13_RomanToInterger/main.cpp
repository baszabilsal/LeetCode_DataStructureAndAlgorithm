#include <bits/stdc++.h>
using namespace std;
int getValue(char str)
{
    int output = 0;
    switch (str)
    {
    case 'I':
        output = 1;
        break;
    case 'V':
        output = 5;
        break;
    case 'X':
        output = 10;
        break;
    case 'L':
        output = 50;
        break;
    case 'C':
        output = 100;
        break;
    case 'D':
        output = 500;
        break;
    case 'M':
        output = 1000;
        break;
    }

    return output;
}
int romanToInt(string s)
{
    int output = 0;
    int t = 0;
    while (t < s.size())
    {
        int value = getValue(s[t]);
        int outputPerPosition = value;
        t++;
        int nextValue = getValue(s[t]);
        while (t < s.size() && nextValue >= value)
        {
            t++;
            if (nextValue == value)
            {
                outputPerPosition += nextValue;
            }
            else
            {
                outputPerPosition = nextValue - outputPerPosition;
            }
            nextValue = getValue(s[t]);
        }
        output += outputPerPosition;
    }
    return output;
}
int main()
{
    cout << romanToInt("CM") << endl;
    return 0;
}