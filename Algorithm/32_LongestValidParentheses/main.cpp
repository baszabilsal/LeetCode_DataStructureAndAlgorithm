#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int total = 0;
        if (s.size() > 1)
        {
            stack<int> st;
            st.push(-1);
            int start = 0;
            while (start < s.size())
            {
                int top = st.top();
                if (top != -1 && s[top] == '(' && s[start] == ')' && st.size() > 1)
                {
                    st.pop();
                    total = max(total, start - st.top());
                }
                else
                {
                    st.push(start);
                }
                start++;
            }
        }
        return total;
    }
};
int main()
{
    Solution st;
    string s = "(())";
    cout << st.longestValidParentheses(s) << endl;
}