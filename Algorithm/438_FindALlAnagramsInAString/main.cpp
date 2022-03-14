#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        map<char, int> m;
        for (int i = 0; i < p.size(); i++)
        {
            m[p[i]]++;
        }
        int start = 0;
        int end = 0;
        vector<int> output;
        while (end < s.size())
        {
            m[s[end]]--;
            if (m[s[end]] == 0)
            {
                m.erase(s[end]);
            }
            if (end - start < (p.size() - 1))
            {
                end++;
            }
            else if (end - start == (p.size() - 1))
            {
                if (m.size() == 0)
                {
                    output.push_back(start);
                }
                m[s[start]]++;
                if (m[s[start]] == 0)
                {
                    m.erase(s[start]);
                }
                start++;
                end++;
            }
        }
        return output;
    }
};
int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution st;
    vector<int> output = st.findAnagrams(s, p);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}