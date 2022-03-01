#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    string num = to_string(x);
    int r, l;
    if (num.size() % 2 > 0)
    {
        l = (int)(num.size() / 2);
        r = (int)(num.size() / 2);
    }
    else
    {
        l = (int)(num.size() / 2) - 1;
        r = (int)(num.size() / 2);
    }
    while (l >= 0 && r < num.size())
    {
        if (num[l] != num[r])
            return false;
        l++;
        r--;
    }
    return true;
}
int main()
{
    cout << isPalindrome(-10011) << endl;
    return 0;
}