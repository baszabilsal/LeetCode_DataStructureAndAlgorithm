#include <bits/stdc++.h>
using namespace std;
int titleToNumber(string columnTitle)
{
    int c = 'A' - 1;
    int d = 0;
    int start = columnTitle.size() - 1;
    for (int i = start; i >= 0; i--)
    {
        int a = columnTitle[start - i];
        d += (a - c) * pow(26, i);
    }
    return d;
}
int main()
{
    cout << pow(2, 3) << endl;
    return 0;
}