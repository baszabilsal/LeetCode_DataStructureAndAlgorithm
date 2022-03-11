#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> output;
    int count = 0;
    void solve(int start, int end, string temp)
    {
        cout << count++ << " : " << temp << endl;
        if (start == 0 && end == 0)
        {
            output.push_back(temp);
        }
        else
        {
            if (start != 0)
            {
                string temp1 = temp;
                temp1 += "(";
                solve(start - 1, end, temp1);
            }
            if (end > start)
            {
                string temp2 = temp;
                temp2 += ")";
                solve(start, end - 1, temp2);
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        solve(n, n, "");
        return output;
    }
};
int main()
{
    Solution st;
    int n = 2;
    vector<string> output = st.generateParenthesis(n);
    for (int i = 0; i < output.size(); i++)
    {
        // cout << output[i] << endl;
    }
}