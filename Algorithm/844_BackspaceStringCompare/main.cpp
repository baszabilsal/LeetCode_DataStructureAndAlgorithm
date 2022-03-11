#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string _s;
    string _t;
    bool solve(int i, int j, int shiftI, int shirfJ)
    {
        cout << i << " " << j << endl;
        if (i < 0 && j < 0)
        {
            return true;
        }
        if ((i >= 0 && _s[i] == '#') || (j >= 0 && _t[j] == '#'))
        {
            cout << "in " << i << " " << j << endl;
            cout << "in " << _s[i] << " " << _t[j] << endl;
            int ii = i;
            int jj = j;
            if (i >= 0_s [i] == '#')
            {
                shiftI++;
                ii = i - 1;
            }
            if (j >= 0_t [j] == '#')
            {
                shirfJ++;
                jj = j - 1;
            }
            return solve(ii, jj, shiftI, shirfJ);
        }
        else if (shiftI > 0 || shirfJ > 0)
        {
            cout << "clear shift " << shiftI << " " << shirfJ << endl;
            cout << "clear shift " << _s[i] << " " << _t[j] << endl;
            int ii = i;
            int jj = j;
            if (shiftI > 0)
            {
                shiftI--;
                ii = i - 1;
            }
            if (shirfJ > 0)
            {
                shirfJ--;
                jj = j - 1;
            }
            return solve(ii, jj, shiftI, shirfJ);
        }
        bool isMatch = i >= 0 && j >= 0 && _s[i] == _t[j];
        if (isMatch)
        {
            return solve(i - 1, j - 1, 0, 0);
        }
        return false;
    }
    bool backspaceCompare(string s, string t)
    {
        _s = s;
        _t = t;
        return solve(s.size() - 1, t.size() - 1, 0, 0);
    }
};
int main()
{
    Solution st;
    string s = "a##c";
    string t = "#a#c";
    cout << st.backspaceCompare(s, t) << endl;
}