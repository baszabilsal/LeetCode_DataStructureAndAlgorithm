#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> moveX = {1, 0, -1, 0};
    vector<int> moveY = {0, 1, 0, -1};
    bool solve(vector<vector<char>> &board, string word, int x, int y, int start)
    {
        if (start >= word.size())
        {
            return true;
        }
        for (int i = 0; i < 4; i++)
        {
            int xNext = x + moveX[i];
            int yNext = y + moveY[i];
            if (xNext >= 0 && xNext < board.size() && yNext >= 0 && yNext < board[0].size() && board[xNext][yNext] == word[start])
            {
                board[xNext][yNext] = '#';
                bool isSolve = solve(board, word, xNext, yNext, start + 1);
                if (isSolve)
                {
                    return true;
                }
                else
                {
                    board[xNext][yNext] = word[start];
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    board[i][j] = '#';
                    bool isSolve = solve(board, word, i, j, 1);
                    if (isSolve)
                    {
                        return true;
                    }
                    else
                    {
                        board[i][j] = word[0];
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution st;
    vector<vector<char>> nums = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'D', 'D', 'E', 'E'}};
    string s = "SEE";
    cout << st.exist(nums, s) << endl;
}