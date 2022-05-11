#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int count = 1;
    while (t--)
    {
        string s;
        cin >> s;
        string t = "";
        int i = 0;
        while (i < s.size())
        {
            if (i == s.size() - 1 && s[i] < s[i - 1])
            {
                t += s[i];
                t += s[i];
            }
            else if ((i == 0 || (i > 0 && i < s.size() - 1 && s[i] < s[i - 1])) && s[i + 1] >= s[i])
            {
                int start = i;
                while (i < s.size() - 1 && s[i + 1] == s[i])
                {
                    i++;
                }
                cout << i << " " << endl;
                if (i == s.size() - 1 || s[i + 1] > s[i])
                {
                    for (int j = start; j <= i; j++)
                    {
                        t += s[j];
                        t += s[j];
                    }
                }
                else
                {
                    for (int j = start; j <= i; j++)
                    {
                        t += s[j];
                    }
                }
            }
            else
            {
                t += s[i];
            }
            i++;
        }
        cout << "Case #" << count << ": ";
        cout << t << endl;
        count++;
    }
}