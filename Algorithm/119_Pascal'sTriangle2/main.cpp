#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int row, vector<int> &column)
    {
        if (row == 0)
        {
            return;
        }
        int size = column.size();
        vector<int> output;
        output.push_back(1);
        for (int i = 1; i < size; i++)
        {
            output.push_back(column[i] + column[i - 1]);
        }
        output.push_back(1);
        column = output;
        solve(row - 1, column);
    }
    vector<int> getRow(int rowIndex)
    {
        vector<int> output = {1};
        solve(rowIndex, output);
        return output;
    }
};
int main()
{
    Solution st;
    vector<int> output = st.getRow(3);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}