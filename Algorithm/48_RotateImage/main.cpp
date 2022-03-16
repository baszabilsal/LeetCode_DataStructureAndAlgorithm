#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> output;
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> raw;
            for (int j = matrix.size() - 1; j >= 0; j--)
            {
                raw.push_back(matrix[j][i]);
            }
            output.push_back(raw);
        }
        matrix = output;
    }
};
int main()
{
    Solution st;
    vector<vector<int>> b = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    st.rotate(b);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}