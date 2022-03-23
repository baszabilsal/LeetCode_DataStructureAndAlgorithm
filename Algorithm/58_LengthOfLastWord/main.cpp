#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        if (s.size() > 0)
        {
            bool isBreak = false;
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == ' ')
                {
                    if (isBreak)
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    isBreak = true;
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution st;
    cout << st.lengthOfLastWord("Hello World") << endl;

    return 0;
}