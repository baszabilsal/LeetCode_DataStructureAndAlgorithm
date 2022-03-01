#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s)
{
    int l = 0;
    int r = s.size() - 1;
    while (l < r)
    {
        int temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        r--;
        l++;
    }
}
int main()
{
    vector<char> a = {'h', 'e', 'l', 'l', 'o'};
    reverseString(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}