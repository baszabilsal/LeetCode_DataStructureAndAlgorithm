#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int total = 0;
    vector<vector<string>> output;
    vector<string> v;
    bool isValidXY(int x, int y, vector<vector<int>> &board)
    {
        for (int i = 0; i < total; i++)
        {
            if (i != y && board[x][i] == 1)
            {
                return false;
            }
            if (i != x && board[i][y] == 1)
            {
                return false;
            }
        }
        return true;
    }
    bool isValidRightCross(int x, int y, vector<vector<int>> &board)
    {
        int xUp = x;
        int yUp = y;
        while (xUp < total && yUp >= 0)
        {
            if (board[xUp][yUp] == 1)
            {
                return false;
            }
            xUp++;
            yUp--;
        }
        int xDown = x;
        int yDown = y;
        while (xDown >= 0 && yDown < total)
        {
            if (board[xDown][yDown] == 1)
            {
                return false;
            }
            xDown--;
            yDown++;
        }
        return true;
    }
    bool isValidLeftCross(int x, int y, vector<vector<int>> &board)
    {
        int xUp = x;
        int yUp = y;
        while (xUp >= 0 && yUp >= 0)
        {
            if (board[xUp][yUp] == 1)
            {
                return false;
            }
            xUp--;
            yUp--;
        }
        int xDown = x;
        int yDown = y;
        while (xDown < total && yDown < total)
        {
            if (board[xDown][yDown] == 1)
            {
                return false;
            }
            xDown++;
            yDown++;
        }
        return true;
    }
    bool isValid(int x, int y, vector<vector<int>> &board)
    {
        return isValidXY(x, y, board) && isValidRightCross(x, y, board) && isValidLeftCross(x, y, board);
    }
    string getRawString(int x)
    {
        string output = "";
        for (int i = 0; i < total; i++)
        {
            if (i == x)
            {
                output += "Q";
            }
            else
            {
                output += ".";
            }
        }
        return output;
    }
    void solve(int y, vector<vector<int>> &board)
    {
        if (y == total)
        {
            output.push_back(v);
            return;
        }
        for (int i = 0; i < total; i++)
        {
            if (isValid(i, y, board))
            {
                board[i][y] = 1;
                v[i][y] = 'Q';
                solve(y + 1, board);
                v[i][y] = '.';
                board[i][y] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        total = n;
        vector<vector<int>> board(n, vector<int>(n, 0));
        string s = "";
        for (int i = 0; i < n; i++)
            s += ".";
        for (int i = 0; i < n; i++)
            v.push_back(s);
        solve(0, board);
        return output;
    }
};
int main()
{
    Solution st;
    vector<vector<string>> output = st.solveNQueens(4);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " , ";
        }
        cout << endl;
    }
}