#include <bits/stdc++.h>
using namespace std;
string getString(int position, bool isHaft)
{
    if (position == 3)
    {
        return isHaft ? "V" : "I";
    }
    else if (position == 2)
    {
        return isHaft ? "L" : "X";
    }
    else if (position == 1)
    {
        return isHaft ? "D" : "C";
    }
    else
    {
        return "M";
    }
}
string getNumber(int num)
{

    string number = to_string(num);
    if (number.size() == 3)
    {
        number = "0" + number;
    }
    else if (number.size() == 2)
    {
        number = "00" + number;
    }
    else if (number.size() == 1)
    {
        number = "000" + number;
    }
    cout << number << endl;
    return number;
}
string intToRoman(int num)
{
    string number = getNumber(num);
    string output = "";
    for (int i = 0; i < number.size(); i++)
    {
        int d = number[i] - '0';
        if (d >= 1 && d <= 3)
        {
            for (int j = 1; j <= d; j++)
            {
                output += getString(i, false);
            }
        }
        else if (d >= 4 && d <= 8)
        {
            if (d == 4)
            {
                output += getString(i, false);
            }
            output += getString(i, true);
            if (d > 5)
            {
                for (int j = 6; j <= d; j++)
                {
                    output += getString(i, false);
                }
            }
        }
        else if (d == 9)
        {
            output += getString(i, false);
            output += getString(i - 1, false);
        }
    }
    return output;
}
int main()
{
    cout << intToRoman(3) << endl;
    return 0;
}