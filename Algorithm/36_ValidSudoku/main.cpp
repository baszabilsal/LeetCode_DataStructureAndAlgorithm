#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sizeX;
    int sizeY;
    vector<char> charList = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool isValida(vector<vector<char>> &board, int x, int y, char target)
    {
        return isRowValidate(board, x, y, target) &&
               isColumnValidate(board, x, y, target) &&
               isBoxValidate(board, x, y, target);
    }
    bool isRowValidate(vector<vector<char>> &board, int x, int y, char target)
    {
        for (int i = 0; i < sizeX; i++)
        {
            if (i != y && board[x][i] == target)
            {
                return false;
            }
        }
        return true;
    }
    bool isColumnValidate(vector<vector<char>> &board, int x, int y, char target)
    {
        for (int i = 0; i < sizeY; i++)
        {
            if (i != x && board[i][y] == target)
            {
                return false;
            }
        }
        return true;
    }
    bool isBoxValidate(vector<vector<char>> &board, int x, int y, char target)
    {
        int startX = 0;
        int startY = 0;
        if (x > 5)
        {
            startX = 6;
        }
        else if (x > 2)
        {
            startX = 3;
        }
        if (y > 5)
        {
            startY = 6;
        }
        else if (y > 2)
        {
            startY = 3;
        }
        for (int i = startX; i < startX + 3; i++)
        {
            for (int j = startY; j < startY + 3; j++)
            {
                if (i != x && j != y && board[i][j] == target)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int x, int y)
    {
        if (x >= sizeX || y >= sizeY)
        {
            return true;
        }
        if (board[x][y] != '.')
        {
            bool isValidate = isValida(board, x, y, board[x][y]);
            if (!isValidate)
            {
                return false;
            }
        }
        int nextY = (y + 1) % sizeY;
        int nextX = nextY == 0 ? x + 1 : x;
        return solve(board, nextX, nextY);
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        sizeX = board.size();
        sizeY = board[0].size();
        return solve(board, 0, 0);
    }
};
int main()
{
    Solution st;
    vector<vector<char>> image = {{'.', '8', '7', '6', '5', '4', '3', '2', '1'}, {'2', '.', '.', '.', '.', '.', '.', '.', '.'}, {'3', '.', '.', '.', '.', '.', '.', '.', '.'}, {'4', '.', '.', '.', '.', '.', '.', '.', '.'}, {'5', '.', '.', '.', '.', '.', '.', '.', '.'}, {'6', '.', '.', '.', '.', '.', '.', '.', '.'}, {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, {'8', '.', '.', '.', '.', '.', '.', '.', '.'}, {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};
    cout << st.isValidSudoku(image) << endl;
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            cout << " " << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}