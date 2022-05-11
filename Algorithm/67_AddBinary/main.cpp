#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int aSize = a.size();
        int bSize = b.size();
        int maxSize = max(aSize, bSize);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string output = "";
        int add = 0;
        for (int i = 0; i < maxSize; i++)
        {
            if (i < aSize && i < bSize)
            {
                if (a[i] == '1' && b[i] == '1')
                {
                    output += add == 1 ? '1' : '0';
                    add = 1;
                }
                else if (a[i] == '1' || b[i] == '1')
                {
                    if (add == 1)
                    {
                        output += '0';
                        add = 1;
                    }
                    else
                    {
                        output += '1';
                        add = 0;
                    }
                }
                else
                {
                    output += add == 1 ? '1' : '0';
                    add = 0;
                }
            }
            else if (i < aSize)
            {
                if (a[i] == '1')
                {
                    if (add == 1)
                    {
                        output += '0';
                        add = 1;
                    }
                    else
                    {
                        output += '1';
                        add = 0;
                    }
                }
                else
                {
                    output += add == 1 ? '1' : '0';
                    add = 0;
                }
            }
            else if (i < bSize)
            {
                if (b[i] == '1')
                {
                    if (add == 1)
                    {
                        output += '0';
                        add = 1;
                    }
                    else
                    {
                        output += '1';
                        add = 0;
                    }
                }
                else
                {
                    output += add == 1 ? '1' : '0';
                    add = 0;
                }
            }
        }
        if (add == 1)
        {
            output += "1";
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
int main()
{
    Solution st;
    cout << st.addBinary("100", "110010") << endl;
    return 0;
}