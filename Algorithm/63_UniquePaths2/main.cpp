#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int m = 0;
    int n = 0;
    int solve(vector<vector<int>> &obstacleGrid, int x, int y, vector<vector<int>> &DP)
    {
        if (x == m - 1 && y == n - 1)
        {
            return 1;
        }
        else if (x < 0 || x >= m || y < 0 || y >= n)
        {
            return 0;
        }
        else if (obstacleGrid[x][y] == 1)
        {
            return 0;
        }
        if (DP[x][y] != -1)
        {
            return DP[x][y];
        }
        DP[x][y] = 0;
        DP[x][y] += solve(obstacleGrid, x + 1, y, DP);
        DP[x][y] += solve(obstacleGrid, x, y + 1, DP);
        return DP[x][y];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] != 1 && obstacleGrid[0][0] != 1)
        {
            vector<vector<int>> DP(m, vector<int>(n, -1));
            return solve(obstacleGrid, 0, 0, DP);
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    Solution st;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << st.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}