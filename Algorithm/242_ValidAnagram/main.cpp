#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < ransomNote.size(); i++)
        {
            m[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.size(); i++)
        {
            if (!(m.find(magazine[i]) == m.end()))
            {
                m[magazine[i]]--;
                if (m[magazine[i]] == 0)
                {
                    m.erase(magazine[i]);
                }
            }
            if (m.size() == 0)
            {
                return true;
            }
        }
        return m.size() == 0;
    }
};
int main()
{
    Solution st;
    string s = "aab";
    string p = "baa";
    cout << st.canConstruct2(s, p) << endl;
}