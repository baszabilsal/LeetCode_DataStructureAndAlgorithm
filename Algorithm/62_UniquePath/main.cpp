#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> moveX = {0, 1};
    vector<int> moveY = {1, 0};
    int solve(int i, int j, vector<vector<int>> &board, vector<vector<int>> &memory)
    {
        if (i >= board.size() - 1 && j >= board[0].size() - 1)
        {
            return 1;
        }
        if (memory[i][j] != -1)
        {
            return memory[i][j];
        }
        else
        {
            memory[i][j] = 0;
        }
        for (int k = 0; k < 2; k++)
        {
            int x = i + moveX[k];
            int y = j + moveY[k];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 0)
            {
                board[x][y] = 1;
                memory[i][j] += solve(x, y, board, memory);
                board[x][y] = 0;
            }
        }
        return memory[i][j];
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memory(m + 1, vector<int>(n + 1, -1));
        vector<vector<int>> board(m, vector<int>(n, 0));
        return solve(0, 0, board, memory);
    }
};
int main()
{
    Solution st;
    cout << st.uniquePaths(28, 12) << endl;
}