#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> moveX = {1, 0, 1, -1, -1, 1, -1, 0};
    vector<int> moveY = {1, 1, 0, 1, 0, -1, -1, -1};
    int xSize = 0;
    int ySize = 0;
    bool isValidate(int x, int y, vector<vector<int>> &grid)
    {
        return x >= 0 && x < xSize && y >= 0 && y < ySize && (grid[x][y] == 0);
    }
    int solve(int start, int x, int y, vector<vector<int>> &grid)
    {
        if (x == xSize - 1 && y == ySize - 1)
        {
            return start;
        }
        if (isValidate(x, y, grid))
        {
            grid[x][y] = 1;
            int moveTotal = -1;
            bool isAlreadySet = false;
            for (int i = 0; i < 8; i++)
            {
                int xNext = x + moveX[i];
                int yNext = y + moveY[i];
                if (isValidate(xNext, yNext, grid))
                {
                    int minMove = solve(start + 1, xNext, yNext, grid);
                    if (minMove != -1)
                    {
                        if (isAlreadySet)
                        {
                            moveTotal = min(minMove, moveTotal);
                        }
                        else
                        {
                            isAlreadySet = true;
                            moveTotal = minMove;
                        }
                    }
                }
            }
            grid[x][y] = 0;
            return moveTotal;
        }
        else
        {
            return -1;
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        xSize = grid.size();
        ySize = grid[0].size();
        if (grid[0][0] != 0 || grid[xSize - 1][ySize - 1] != 0)
        {
            return -1;
        }
        else
        {
            return solve(1, 0, 0, grid);
        }
    }
};
class ImproveSolution
{
public:
    vector<int> moveX = {1, 0, 1, -1, -1, 1, -1, 0};
    vector<int> moveY = {1, 1, 0, 1, 0, -1, -1, -1};
    bool isValidate(int x, int y, vector<vector<int>> &grid)
    {
        int xSize = grid.size();
        int ySize = grid[0].size();
        return x >= 0 && x < xSize && y >= 0 && y < ySize && (grid[x][y] == 0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int xSize = grid.size();
        int ySize = grid[0].size();
        if (grid[0][0] != 0 || grid[xSize - 1][ySize - 1] != 0)
        {
            return -1;
        }
        else if (xSize == 1 && ySize == 1 && grid[0][0] == 0)
        {
            return 1;
        }
        else
        {
            queue<pair<int, int>> q;
            grid[0][0] = 1;
            q.push({0, 0});
            int count = 0;
            while (q.size() != 0)
            {
                int size = q.size();
                count++;
                while (size--)
                {
                    auto s = q.front();
                    q.pop();
                    int x = s.first;
                    int y = s.second;
                    for (int i = 0; i < 8; i++)
                    {
                        int xNext = x + moveX[i];
                        int yNext = y + moveY[i];
                        if (isValidate(xNext, yNext, grid))
                        {
                            if (xNext == xSize - 1 && yNext == ySize - 1)
                            {
                                count++;
                                return count;
                            }
                            grid[xNext][yNext] = 1;
                            q.push({xNext, yNext});
                        }
                    }
                }
            }
            return count;
        }
    }
};
int main()
{
    ImproveSolution st;
    vector<vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << st.shortestPathBinaryMatrix(grid) << endl;
}