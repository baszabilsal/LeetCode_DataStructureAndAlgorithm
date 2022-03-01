#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    string temp = "";
    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (temp.find(s[i]) < temp.size())
        {
            size_t position = temp.find(s[i]);
            temp = temp.substr(position + 1);
        }
        temp += s[i];
        int size = temp.size();
        if (max < size)
        {
            max = size;
        }
    }
    return max;
}
int main()
{
    string a = "abcad";
    cout << lengthOfLongestSubstring(a) << endl;

    return 0;
}