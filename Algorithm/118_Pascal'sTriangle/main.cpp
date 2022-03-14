#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    int max;
    void solve(int start)
    {
        if (start > max)
        {
            return;
        }
        vector<int> raw;
        for (int i = 0; i < start; i++)
        {
            if (i == 0 || i == start - 1)
            {
                raw.push_back(1);
            }
            else
            {
                raw.push_back(output[start - 2][i] + output[start - 2][i - 1]);
            }
        }
        output.push_back(raw);
        solve(start + 1);
    }
    vector<vector<int>> generate(int numRows)
    {
        max = numRows;
        solve(1);
        return output;
    }
};
int main()
{
    Solution st;
    vector<vector<int>> output = st.generate(10);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}