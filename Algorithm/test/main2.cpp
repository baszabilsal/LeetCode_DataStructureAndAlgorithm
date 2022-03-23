#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string solve(string n)
    {
        int count = 0;
        for (int i = 0; i < n.size(); i++)
        {
            count += (n[i] - '0');
            count %= 9;
        }
        count = (9 - count) % 9;
        char x = '0' + count;
        int minValue = 0;
        string output = "";
        bool isSet = false;
        int startPoint = x != '0' ? 0 : 1;
        if (startPoint > 0)
        {
            output += n[0];
        }
        for (auto c : n)
        {
            if (c > x && !isSet)
            {
                output += x;
                isSet = true;
            }
            output += c;
        }
        if (!isSet)
            output += x;
        return output;
    }
};
int main()
{
    int t;
    cin >> t;
    Solution st;
    int count = 0;
    while (t--)
    {
        string n;
        cin >> n;
        cout << "Case #" << ++count << ": " << st.solve(n) << endl;
    }
}