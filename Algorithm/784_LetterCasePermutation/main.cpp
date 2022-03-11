#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> output;
    void solve(string s, int i, string raw)
    {
        if (raw.size() == s.size())
        {
            output.push_back(raw);
            return;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            char letter = s[i] - 32;
            solve(s, i + 1, raw + letter);
            raw += s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            char letter = s[i] + 32;
            solve(s, i + 1, raw + letter);
            raw += s[i];
        }
        else
        {
            raw += s[i];
        }
        solve(s, i + 1, raw);
    }
    vector<string> letterCasePermutation(string s)
    {
        solve(s, 0, "");
        return output;
    }
};

int main()
{
    Solution st;
    string s = "a1b2";
    vector<string> b = st.letterCasePermutation(s);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << endl;
    }
    cout << endl;
}