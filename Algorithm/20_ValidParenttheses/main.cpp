#include <bits/stdc++.h>
using namespace std;
bool isFront(char c)
{
    int output = false;
    switch (c)
    {
    case '(':
        output = true;
        break;
    case '{':
        output = true;
        break;
    case '[':
        output = true;
        break;
    }
    return output;
}
char getFront(char c)
{
    int output = 0;
    switch (c)
    {
    case ')':
        output = '(';
        break;
    case '}':
        output = '{';
        break;
    case ']':
        output = '[';
        break;
    }
    return output;
}
bool isValid(string s)
{
    if (s.size() % 2 != 0)
    {
        return false;
    }
    else
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (isFront(s[i]))
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                else if (st.top() == getFront(s[i]))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
}
int main()
{
    string s = "){";
    cout << isValid(s) << endl;
}