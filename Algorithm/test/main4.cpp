#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<string, long> m;
    long check(long number)
    {
        string s = to_string(number);
        if (m.find(s) != m.end())
        {
            return m[s] - 1;
        }
        else
        {
            long a = 1;
            long b = 0;
            for (long i = 0; i < s.size(); i++)
            {
                a *= (s[i] - '0');
                b += (s[i] - '0');
            }
            if (a % b == 0)
            {
                m[s] = 2;
                return 1;
            }
            else
            {
                m[s] = 1;
                return 0;
            }
        }
    }
    long solve(long s, long n)
    {
        long output = 0;
        for (long i = s; i <= n; i++)
        {
            output += check(i);
        }
        return output;
    }
};
int main()
{
    long t;
    cin >> t;
    Solution st;
    long count = 0;
    while (t--)
    {
        long s;
        long n;
        cin >> n >> s;
        cout << "Case #" << ++count << ": " << st.solve(n, s) << endl;
    }
}