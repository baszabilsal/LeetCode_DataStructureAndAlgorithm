#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> moveX = {1, 0, -1, 0};
    vector<int> moveY = {0, 1, 0, -1};
    vector<vector<int>> generateMatrix2(int n)
    {
        vector<vector<int>> output(n, vector<int>(n, 0));
        stack<pair<int, int>> st;
        int move = 0;
        int count = 0;
        st.push({0, 0});
        while (st.size() > 0)
        {
            auto p = st.top();
            st.pop();
            output[p.second][p.first] = ++count;
            int x = p.first + moveX[move];
            int y = p.second + moveY[move];
            if (x >= 0 && x < n && y >= 0 & y < n && output[y][x] == 0)
            {
                st.push({x, y});
            }
            else
            {
                move++;
                move %= 4;
                x = p.first + moveX[move];
                y = p.second + moveY[move];
                if (x >= 0 && x < n && y >= 0 & y < n && output[y][x] == 0)
                {
                    st.push({x, y});
                }
            }
        }
        return output;
    }
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> output(n, vector<int>(n, 0));
        stack<pair<int, int>> st;
        int move = 0;
        int count = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < n * n; i++)
        {
            output[y][x] = ++count;
            x += moveX[move];
            y += moveY[move];
            if (!(x >= 0 && x < n && y >= 0 & y < n && output[y][x] == 0))
            {
                x -= moveX[move];
                y -= moveY[move];
                move++;
                move %= 4;
                x += moveX[move];
                y += moveY[move];
            }
        }
        return output;
    }
};
int main()
{
    Solution st;
    vector<vector<int>> intervals = st.generateMatrix(3);
    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals[i].size(); j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}