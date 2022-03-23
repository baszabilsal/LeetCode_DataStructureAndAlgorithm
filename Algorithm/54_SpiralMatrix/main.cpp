#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> output;
    vector<int> moveX = {1, 0, -1, 0};
    vector<int> moveY = {0, 1, 0, -1};
    stack<pair<int, int>> st;
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int direction = 0;
        st.push({0, 0});
        output.push_back(matrix[0][0]);
        matrix[0][0] = 101;
        while (st.size() > 0)
        {
            auto p = st.top();
            st.pop();
            int x = p.first + moveX[direction];
            int y = p.second + moveY[direction];
            if (x >= 0 && x < matrix[0].size() && y >= 0 && y < matrix.size() && matrix[y][x] != 101)
            {
                output.push_back(matrix[y][x]);
                matrix[y][x] = 101;
                st.push({x, y});
            }
            else
            {
                direction = (direction + 1) % 4;
                x = p.first + moveX[direction];
                y = p.second + moveY[direction];
                if (x >= 0 && x < matrix[0].size() && y >= 0 && y < matrix.size() && matrix[y][x] != 101)
                {
                    output.push_back(matrix[y][x]);
                    matrix[y][x] = 101;
                    st.push({x, y});
                }
            }
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<vector<int>> inptut = {{1}};
    vector<int> output = st.spiralOrder(inptut);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}