#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int output = 0;
    string number = "";
    bool isNegative = false;
    bool isDetectNumberNegative = false;
    bool isDetectNumber = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' <= 10 && s[i] - '0' >= 0)
        {
            number += s[i];
            isDetectNumber = true;
        }
        else if (s[i] == '-' && !isDetectNumber && !isDetectNumberNegative)
        {
            isDetectNumberNegative = true;
            isNegative = true;
        }
        else if (s[i] == '+' && !isDetectNumber && !isDetectNumberNegative)
        {
            isDetectNumberNegative = true;
            isNegative = false;
        }
        else if (isDetectNumber || isDetectNumberNegative)
        {
            break;
        }
        else if (!isDetectNumber && s[i] != ' ')
        {
            return 0;
        }
    }
    try
    {
        output = stoi(number) * (isNegative ? -1 : 1);
    }
    catch (const std::exception &e)
    {
        if (!isDetectNumber)
        {
            return 0;
        }
        if (isNegative)
        {
            output = INT_MIN;
        }
        else
        {
            output = INT_MAX;
        }
    }
    return output;
}
int main()
{
    string s = "-15638412afsdf";
    cout << myAtoi(s) << endl;
    return 0;
}