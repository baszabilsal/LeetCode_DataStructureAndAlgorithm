#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int actualR = mat.size();
        int actualC = mat[0].size();
        if (r * c == actualR * actualC)
        {
            vector<vector<int>> output;
            int count = 0;
            int row = 0;
            int mod = 0;
            for (int i = 0; i < r; i++)
            {
                vector<int> raw;
                for (int j = 0; j < c; j++)
                {
                    mod = count % actualC;
                    row = count / actualC;
                    raw.push_back(mat[row][mod]);
                    count++;
                }
                output.push_back(raw);
            }
            return output;
        }
        else
        {
            return mat;
        }
    }
};
int main()
{
    vector<vector<int>> mat = {{1, 2}, {3, 4}, {5, 7}};
    Solution st;
    vector<vector<int>> output = st.matrixReshape(mat, 3, 2);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}