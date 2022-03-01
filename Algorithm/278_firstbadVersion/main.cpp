#include <bits/stdc++.h>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
int isBadVersion(int n);
int firstBadVersion(int n)
{
    int l = 1, r = n;
    while (l < r)
    {
        int med = l / 2 + r / 2;
        if (isBadVersion(med))
            r = med;
        else
            l = med + 1;
    }
    return r;
}
int main()
{
    cout << firstBadVersion(a, 2) << endl;
    return 0;
}