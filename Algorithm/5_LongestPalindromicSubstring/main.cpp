#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s)
{
    int maxL = 0;
    int maxR = 0;
    int count = -1;
    for (int i = 0; i < s.size(); i++)
    {
        int r = i;
        int l = i;
        while (l >= 0 && r < s.size() && s[r] == s[l])
        {
            if ((r - l + 1) > count)
            {
                maxL = l;
                maxR = r + 1;
                count = r - l + 1;
            }
            l--;
            r++;
        }
        r = i + 1;
        l = i;
        while (l >= 0 && r < s.size() && s[r] == s[l])
        {
            if ((r - l + 1) > count)
            {
                maxL = l;
                maxR = r + 1;
                count = r - l + 1;
            }
            l--;
            r++;
        }
    }

    return s.substr(maxL, (maxR - maxL));
}
int main()
{
    string s = "babad";
    cout << singleNumber(nums) << endl;
}