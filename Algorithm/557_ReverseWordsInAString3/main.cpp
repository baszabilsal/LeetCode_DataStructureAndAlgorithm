#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    string output = "";
    string tempString = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            tempString += s[i];
        }
        else
        {
            output = tempString + (output != "" ? " " : "") + output;
            tempString = "";
        }
    }
    if (tempString != "")
    {
        output = tempString + (output != "" ? " " : "") + output;
    }
    return output;
}
string reverseWords2(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int start = i;
        int end = i;
        while (end < s.size() && s[end] != ' ')
            end++;
        i = end;
        end--;
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    return s;
}
int main()
{
    string a = "Let's take LeetCode contest";
    string output = reverseWords2(a);

    cout << output << endl;
    return 0;
}