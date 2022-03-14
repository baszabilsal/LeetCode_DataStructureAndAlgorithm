#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n)
{
    string output = "1";
    n--;
    while (n--)
    {
        string raw = "";
        for (int i = 0; i < output.size(); i++)
        {
            int p = i;
            while (i + 1 < output.size() && output[i] == output[i + 1])
                i++;
            raw += to_string((i - p) + 1) + output[i];
        }
        output = raw;
    }
    return output;
}
int main()
{

    cout << countAndSay(4) << endl;
    return 0;
}