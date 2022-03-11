#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string _s;
    string _p;
    bool solve(int i, int j)
    {
        if (i >= _s.size() && j >= _p.size())
        {
            return true;
        }
        bool isMatch = i < _s.size() && j < _p.size() && (_s[i] == _p[j] || _p[j] == '.');
        if (j + 1 < _p.size() && _p[j + 1] == '*')
        {
            bool isCheckPreChar = isMatch && solve(i + 1, j);
            if (isCheckPreChar)
            {
                return true;
            }
            bool ignoreChar = solve(i, j + 2);
            return ignoreChar;
        }
        if (isMatch)
        {
            return solve(i + 1, j + 1);
        }
        return false;
    }
    bool isMatch(string s, string p)
    {
        _s = s;
        _p = p;
        return solve(0, 0);
    }
};
class Solution2
{
public:
    string _s;
    string _p;
    bool solve(int i, int j)
    {
        if (i >= _s.size() && j >= _p.size())
        {
            return true;
        }
        bool isMatch = i < _s.size() && j < _p.size() && (_s[i] == _p[j] || _p[j] == '.');
        if (j + 1 < _p.size() && _p[j + 1] == '*')
        {
            bool isCheckPreChar = isMatch && solve(i + 1, j);
            bool ignoreChar = solve(i, j + 2);
            return ignoreChar || isCheckPreChar;
        }
        if (isMatch)
        {
            return solve(i + 1, j + 1);
        }
        return false;
    }
    bool isMatch(string s, string p)
    {
        _s = s;
        _p = p;
        return solve(0, 0);
    }
};
class Solution3
{
public:
    bool solve(string s, string p, int i, int j)
    {
        if (i >= s.size() && j >= p.size())
        {
            return true;
        }
        bool isMatch = i < s.size() && j < p.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            bool isCheckPreChar = isMatch && solve(s, p, i + 1, j);
            if (isCheckPreChar)
            {
                return true;
            }
            bool ignoreChar = solve(s, p, i, j + 2);
            return ignoreChar;
        }
        if (isMatch)
        {
            return solve(s, p, i + 1, j + 1);
        }
        return false;
    }
    bool isMatch(string s, string p)
    {
        return solve(s, p, 0, 0);
    }
};
int main()
{
    Solution st;
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    cout << st.isMatch(s, p) << endl;
}