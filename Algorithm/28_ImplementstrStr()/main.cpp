#include <bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle)
{
    int output = -1;
    if (needle.size() == 0)
    {
        output = 0;
    }
    else if (haystack.size() != 0)
    {
        for (int i = 0; i < (haystack.size()); i++)
        {

            if (i + (needle.size() - 1) >= haystack.size())
            {
                break;
            }
            bool isSuccess = true;
            for (int j = 0; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    isSuccess = false;
                }
            }
            if (isSuccess)
            {
                output = i;
                break;
            }
        }
    }
    return output;
}
int main()
{
    string haystack = "";
    string needle = "l";
    cout << strStr(haystack, needle) << endl;
}