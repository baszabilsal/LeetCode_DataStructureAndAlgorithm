#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> output;
        map<string, int> m;
        int len = words[0].size();
        int wlen = words.size() * len;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]] += 1;
        }
        for (int i = 0; i < s.size() - (wlen - 1); i++)
        {
            map<string, int> mHash;
            for (int j = i; j < i + wlen; j = j + len)
            {
                mHash[s.substr(j, len)] += 1;
            }
            if (mHash == m)
            {
                output.push_back(i);
            }
        }
        return output;
    }
    vector<int> findSubstringImplement(string s, vector<string> &words)
    {
        vector<int> output;
        unordered_map<string, int> m;
        unordered_map<string, int> mTemp;
        int len = words[0].size();
        int wlen = words.size() * len;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]] += 1;
            mTemp[words[i]] += 1;
        }
        for (int i = 0; i < s.size() - (wlen - 1); i++)
        {
            unordered_map<string, int> mHash;
            bool isBreak = false;
            for (int j = i; j < i + wlen && !isBreak; j = j + len)
            {
                string str = s.substr(j, len);
                if (m[str] > 0)
                {
                    mHash[str] += 1;
                }
                else
                {
                    isBreak = true;
                }
            }
            if (mHash == mTemp)
            {
                output.push_back(i);
            }
        }
        return output;
    }
};
int main()
{
    Solution st;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word", "good", "good", "best"};
    vector<int> output = st.findSubstring(s, words);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}