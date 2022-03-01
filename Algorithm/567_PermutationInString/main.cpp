#include <bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2)
{
    map<char, int> m;
    for (int i = 0; i < s1.size(); i++)
    {
        m[s1[i]] += 1;
    }
    int count = 0;
    int size = s1.size();
    for (int i = 0; i < s2.size(); i++)
    {

        if (m.find(s2[i]) != m.end())
        {
            m[s2[i]] -= 1;
            count++;
        }
        if (count == s1.size())
        {
            return true;
        }
        int lastStringIndex = i - (size - 1);
        if (lastStringIndex >= 0)
        {
            if (m.find(s2[lastStringIndex]) != m.end())
            {
                m[s2[lastStringIndex]] += 1;
                count = count > 0 ? (count - 1) : 0;
            }
        }
        cout << s2[i] << " " << count << endl;
    }
    return false;
}
int main()
{
    string a = "hello";
    string b = "ooolleoooleh";
    cout << checkInclusion(a, b) << endl;

    return 0;
}