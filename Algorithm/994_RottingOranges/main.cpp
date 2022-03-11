#include <bits/stdc++.h>
using namespace std;
class Solution1
{
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>> &grid)
    {

        queue<pair<int, int>> queue;

        int freshOranges = 0;
        int R = grid.size();
        int C = grid[0].size();

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {

                if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
                else if (grid[i][j] == 2)
                {
                    queue.push({i, j});
                }
            }
        }

        int time = 0;
        while (queue.size() > 0)
        {
            int count = queue.size();
            cout << "count :" << count << endl;
            while (count > 0)
            {
                pair<int, int> current = queue.front();
                queue.pop();
                count--;
                int x = current.first;
                int y = current.second;
                for (auto dir : directions)
                {

                    int xx = x + dir[0];
                    int yy = y + dir[1];
                    if (isValid(xx, yy, R, C) && grid[xx][yy] == 1)
                    {
                        cout << "next :" << xx << yy << endl;
                        queue.push({xx, yy});
                        grid[xx][yy] = 2;
                        freshOranges--;
                    }
                }
            }
            cout << "time :" << time << endl;
            time++;
        }

        if (time == 0)
        {
            time = 1;
        }
        return freshOranges > 0 ? -1 : time - 1;
    }

    bool isValid(int x, int y, int R, int C)
    {
        if (x < 0 || y < 0 || x >= R || y >= C)
        {
            return false;
        }

        return true;
    }
};
class Solution
{
public:
    int nextXar[4] = {0, 1, 0, -1};
    int nextYar[4] = {1, 0, -1, 0};

    bool isConnect(vector<vector<int>> &grid, int x, int y, int maxX, int maxY)
    {
        bool isConnect = false;
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + nextXar[i];
            int nextY = y + nextYar[i];
            if (nextX >= 0 and nextX < maxX and nextY >= 0 and nextY < maxY and grid[nextX][nextY] >= 1)
            {
                isConnect = true;
            }
        }
        return isConnect;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int min = 0;
        int fresh = 0;
        queue<pair<int, int>> _queue;
        int maxX = grid.size();
        int maxY = grid[0].size();
        for (int i = 0; i < maxX; i++)
        {
            for (int j = 0; j < maxY; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                    if (!isConnect(grid, i, j, maxX, maxY))
                    {
                        return -1;
                    }
                }
                else if (grid[i][j] == 2)
                {
                    fresh++;
                    _queue.push({i, j});
                    min = -1;
                }
            }
        }
        while (_queue.size() > 0)
        {
            int count = _queue.size();
            cout << count << endl;
            while (count)
            {
                count--;
                pair<int, int> p = _queue.front();
                _queue.pop();
                int x = p.first;
                int y = p.second;
                cout << " postiohn :" << x << y << endl;
                grid[x][y] = 2;
                fresh--;
                for (int i = 0; i < 4; i++)
                {
                    int nextX = x + nextXar[i];
                    int nextY = y + nextYar[i];
                    if (nextX >= 0 and nextX < maxX and nextY >= 0 and nextY < maxY and grid[nextX][nextY] == 1)
                    {
                        _queue.push({nextX, nextY});
                    }
                }
            }
            min++;
        }
        return fresh > 0 ? -1 : min;
    }
};
int main()
{
    vector<vector<int>> grid = {{2, 2}, {1, 1}, {0, 0}, {2, 0}};
    Solution1 st;
    cout << st.orangesRotting(grid) << endl;
}