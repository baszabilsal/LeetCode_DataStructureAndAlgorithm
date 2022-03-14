#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    string a = "S";
    std::for_each(a.begin(), a.end(), [](char &c)
                  { c = ::tolower(c); });
    cout << a << endl;
}