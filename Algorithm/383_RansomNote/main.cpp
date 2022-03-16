#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() == t.size())
        {
            unordered_map<int, int> m;
            for (int i = 0; i < s.size(); i++)
            {
                m[s[i]]++;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                m[t[i]]--;
                if (m[t[i]] == 0)
                {
                    m.erase(t[i]);
                }
            }
            return m.size() == 0;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Solution st;
    string s = "aab";
    string p = "baa";
    cout << st.isAnagram(s, p) << endl;
}