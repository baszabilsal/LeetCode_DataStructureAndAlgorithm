#include <bits/stdc++.h>
using namespace std;
string convert(string s, int numRows)
{
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string output = "";
        output += s[0];
        int t = 1;
        int rowNumber = 1;
        int direction = 1;
        string row[numRows];
        while (t < s.size())
        {
            row[rowNumber] += s[t];
            if (t % (numRows - 1) == 0)
            {
                direction *= -1;
            }
            t++;
            rowNumber += direction;
        }
        for (auto selectedRow : row)
        {
            output += selectedRow;
        }
        return output;
    }
    int main()
    {
        string s = "PAYPALISHIRING";
        int n = 3;
        cout << convert(s, n) << endl;
        return 0;
    }