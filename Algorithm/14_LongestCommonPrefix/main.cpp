#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
    {
        return strs[0];
    }
    string output = "";
    int minSize = strs[0].size();
    for (int i = 1; i < strs.size(); i++)
    {
        if (minSize < strs[i].size())
        {
            minSize = strs[i].size();
        }
    }
    int l = 0;
    int r = minSize + 1;
    while (l < r)
    {
        int med = (l + r) / 2;
        string raw = strs[0].substr(0, med);
        bool isSame = true;
        for (int i = 1; i < strs.size() && isSame; i++)
        {
            if (strs[i].substr(0, med) != raw)
            {
                isSame = false;
            }
        }
        if (isSame)
        {
            output = raw;
            l = med + 1;
        }
        else
        {
            r = med;
        }
    }
    return output;
}
int main()
{
    vector<string> s = {"flower", "flower", "flower"};
    cout << longestCommonPrefix(s) << endl;
    return 0;
}