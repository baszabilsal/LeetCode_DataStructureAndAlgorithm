#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<char>> _board;
    queue<pair<int, int>> _queue;
    vector<int> moveX = {0, 1, -1, 0};
    vector<int> moveY = {1, 0, 0, -1};
    void solve(vector<vector<char>> &board)
    {
        if (board.size() != 1 && board[0].size() != 1)
        {
            _board = board;
            for (int i = 0; i < _board.size(); i++)
            {
                for (int j = 0; j < _board[0].size(); j++)
                {
                    if (_board[i][j] == 'O')
                    {
                        _board[i][j] = '#';
                        _queue.push({i, j});
                        bfs();
                    }
                }
            }
            board = _board;
        }
    }
    bool isValid(int x, int y)
    {
        return (x >= 0 && x < _board.size() && y >= 0 && y < _board[0].size() && _board[x][y] == 'O');
    }
    bool isBoard(int x, int y)
    {
        return (x < 0 || x >= _board.size() || y < 0 || y >= _board[0].size());
    }
    void bfs()
    {
        vector<pair<int, int>> stack;
        bool isFindBoard = 0;
        while (_queue.size() > 0)
        {
            auto p = _queue.front();
            stack.push_back(p);
            _queue.pop();
            int x = p.first;
            int y = p.second;
            for (int j = 0; j < 4; j++)
            {
                int xMove = x + moveX[j];
                int yMove = y + moveY[j];
                cout << xMove << " " << yMove << endl;
                if (!isFindBoard)
                {
                    isFindBoard = isBoard(xMove, yMove);
                }
                if (isValid(xMove, yMove))
                {
                    _board[xMove][yMove] = '#';
                    _queue.push({xMove, yMove});
                }
            }
        }
        for (int i = 0; i < stack.size(); i++)
        {
            int xMove = stack[i].first;
            int yMove = stack[i].second;
            if (!isFindBoard)
            {
                _board[xMove][yMove] = 'X';
            }
            else
            {
                _board[xMove][yMove] = 'O';
            }
        }
    }
};
int main()
{
    Solution st;
    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board = {{'O', 'O'}, {'X', 'X'}};
    st.solve(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}