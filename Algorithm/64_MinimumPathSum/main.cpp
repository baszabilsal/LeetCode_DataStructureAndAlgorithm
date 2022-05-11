#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<vector<int>> &grid, vector<vector<int>> &DP, int x, int y)
    {
        if (x == grid.size() - 1 && y == grid[0].size() - 1)
        {
            return grid[grid.size() - 1][grid[0].size() - 1];
        }
        if (DP[x][y] != -1)
        {
            return DP[x][y];
        }
        int minSum = -1;
        if (x + 1 < grid.size())
        {
            minSum = solve(grid, DP, x + 1, y);
        }
        if (y + 1 < grid[0].size())
        {
            int temp = solve(grid, DP, x, y + 1);
            if (minSum > temp || minSum == -1)
            {
                minSum = temp;
            }
        }
        return DP[x][y] = minSum + grid[x][y];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> DP(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, DP, 0, 0);
    }
    int minPathSum2(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i != 0 || j != 0)
                {
                    if (j == 0)
                    {
                        grid[i][j] = grid[i][j] + grid[i - 1][j];
                    }
                    else if (i == 0)
                    {
                        grid[i][j] = grid[i][j] + grid[i][j - 1];
                    }
                    else
                    {
                        int minValue = grid[i][j] + grid[i][j - 1];
                        if (minValue > grid[i][j] + grid[i - 1][j])
                        {
                            minValue = grid[i][j] + grid[i - 1][j];
                        }
                        grid[i][j] = minValue;
                    }
                }
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
int main()
{
    Solution st;
    vector<vector<int>> obstacleGrid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << st.minPathSum2(obstacleGrid) << endl;

    return 0;
}