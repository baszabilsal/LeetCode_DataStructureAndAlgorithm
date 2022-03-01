#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int row, int column, int max)
{
    int maxRow = grid.size();
    int maxColumn = grid[0].size();
    if (row < 0 || row >= maxRow || column < 0 || column >= maxColumn || grid[row][column] != 1)
    {
        return max;
    }
    max++;
    grid[row][column] = max + 1;
    int rowMove[4] = {1, 0, -1, 0};
    int columnMove[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + rowMove[i];
        int nextColumn = column + columnMove[i];
        max = solve(grid, nextRow, nextColumn, max);
    }
    return max;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int maxRow = grid.size();
    int maxColumn = grid[0].size();
    int max = 0;
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxColumn; j++)
        {
            int maxLand = solve(grid, i, j, 0);
            if (max < maxLand)
            {
                max = maxLand;
            }
        }
    }
    return max;
}
int main()
{
    vector<vector<int>> image = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int max = maxAreaOfIsland(image);

    int maxRow = image.size();
    int maxColumn = image[0].size();
    cout << max << endl
         << endl;
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxColumn; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}