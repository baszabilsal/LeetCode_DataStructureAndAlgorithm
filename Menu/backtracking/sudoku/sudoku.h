#include <bits/stdc++.h>
using namespace std;
class Sudoku
{
public:
    static const int size = 9;

private:
    int board[size][size] = {{0, 4, 0, 0, 0, 0, 1, 7, 9},
                             {0, 0, 2, 0, 0, 8, 0, 5, 4},
                             {0, 0, 6, 0, 0, 5, 0, 0, 8},
                             {0, 8, 0, 0, 7, 0, 9, 1, 0},
                             {0, 5, 0, 0, 9, 0, 0, 3, 0},
                             {0, 1, 9, 0, 6, 0, 0, 4, 0},
                             {3, 0, 0, 4, 0, 0, 7, 0, 0},
                             {5, 7, 0, 1, 0, 0, 2, 0, 0},
                             {9, 2, 8, 0, 0, 0, 0, 6, 0}};
    int boardSolved[size][size] = {{8, 4, 5, 6, 3, 2, 1, 7, 9},
                                   {7, 3, 2, 9, 1, 8, 6, 5, 4},
                                   {1, 9, 6, 7, 4, 5, 3, 2, 8},
                                   {6, 8, 3, 5, 7, 4, 9, 1, 2},
                                   {4, 5, 7, 2, 9, 1, 8, 3, 6},
                                   {2, 1, 9, 8, 6, 3, 5, 4, 7},
                                   {3, 6, 1, 4, 2, 9, 7, 8, 5},
                                   {5, 7, 4, 1, 8, 6, 2, 9, 3},
                                   {9, 2, 8, 3, 5, 7, 4, 6, 1}};
    int boardError[size][size];

public:
    void clearBoard()
    {
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                board[i][j] = 0;
            }
        }
    }
    void readInput()
    {
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                cin >> boardSolved[i][j];
            }
        }
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                cin >> board[i][j];
            }
        }
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                cin >> boardError[i][j];
            }
        }
    }
    void print()
    {
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printBoardSolved()
    {
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                cout << boardSolved[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printBoardError()
    {
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                cout << boardError[i][j] << " ";
            }
            cout << endl;
        }
    }
    void checkColumn(int column, int locatedRow)
    {
        for (int i = 0; i < size; i++)
        {
            if (locatedRow == i)
            {
                board[i][column] = 2;
            }
            else
            {
                board[i][column] = 1;
            }
        }
    }
    void checkRow(int row, int locatedColumn)
    {
        for (int i = 0; i < size; i++)
        {
            if (locatedColumn == i)
            {
                board[row][i] = 2;
            }
            else
            {
                board[row][i] = 1;
            }
        }
    }
    void checkBox(int row, int column)
    {
        int boxRow = row / 3;
        int boxColumn = column / 3;
        int t = 0;
        while (t < size)
        {
            int x = t / 3;
            int y = t % 3;
            x += 3 * boxRow;
            y += 3 * boxColumn;
            if (row == x && column == y)
            {
                board[x][y] = 2;
            }
            else
            {
                board[x][y] = 1;
            }
            t++;
        }
    }
    bool validateRow(int row, int locatedColumn, int target)
    {
        for (int i = 0; i < size; i++)
        {
            if (locatedColumn != i && board[row][i] == target)
            {
                return false;
            }
        }
        return true;
    }
    bool validateColumn(int column, int locatedRow, int target)
    {
        for (int i = 0; i < size; i++)
        {
            if (locatedRow != i && board[i][column] == target)
            {
                return false;
            }
        }
        return true;
    }
    bool validateBox(int row, int column, int target)
    {
        int boxRow = row / 3;
        int boxColumn = column / 3;
        int t = 0;
        while (t < size)
        {
            int x = t / 3;
            int y = t % 3;
            x += 3 * boxRow;
            y += 3 * boxColumn;
            if (row != x && column != y && board[x][y] == target)
            {
                return false;
            };
            t++;
        }
        return true;
    }
    bool validateNumber(int row, int column, int number)
    {
        return validateRow(row, column, number) && validateColumn(column, row, number) && validateBox(row, column, number);
    }
    vector<int> getPosibileNumber(int row, int column)
    {
        vector<int> posibileNumbers;
        for (int i = 0; i < size; i++)
        {
            if (validateNumber(row, column, i + 1))
            {
                posibileNumbers.push_back(i + 1);
            }
        }
        return posibileNumbers;
    }
    bool solveJust1Box(int row, int column, int loop)
    {
        int nextColumn, nextRow;
        if (loop % 3 == 0)
        {
            nextColumn = 0;
            nextRow = row + 1;
        }
        else
        {
            nextRow = row;
            nextColumn = column + 1;
        }
        if (board[row][column] != 0)
        {
            loop++;
            row = nextRow;
            column = nextColumn;
            if (loop % 3 == 0 && loop != 0)
            {
                nextColumn = 0;
                nextRow = row + 1;
            }
            else
            {
                nextRow = row;
                nextColumn = column + 1;
            }
        }
        if (loop == 10)
        {
            return true;
        }
        vector<int> posibileNumber = getPosibileNumber(row, column);
        for (int i = 0; i < posibileNumber.size(); i++)
        {
            board[row][column] = posibileNumber[i];
            if (solveJust1Box(nextRow, nextColumn, loop + 1))
            {
                return true;
            }
            else
            {
                board[row][column] = 0;
            }
        }
        return false;
    }
    bool solve(int row, int column, int loop)
    {
        int nextColumn, nextRow;
        if (column != 8)
        {
            nextRow = row;
            nextColumn = column + 1;
        }
        else
        {
            nextColumn = 0;
            nextRow = row + 1;
        }
        if (board[row][column] != 0)
        {
            loop++;
            row = nextRow;
            column = nextColumn;
            if (column != 8)
            {
                nextRow = row;
                nextColumn = column + 1;
            }
            else
            {
                nextColumn = 0;
                nextRow = row + 1;
            }
        }
        if (loop > size * size)
        {
            return true;
        }
        if (board[row][column] != 0)
        {
            solve(nextRow, nextColumn, loop + 1);
        }
        vector<int> posibileNumber = getPosibileNumber(row, column);
        for (int i = 0; i < posibileNumber.size(); i++)
        {
            board[row][column] = posibileNumber[i];
            if (solve(nextRow, nextColumn, loop + 1))
            {
                return true;
            }
            else
            {
                board[row][column] = 0;
            }
        }
        return false;
    }
    void printPosible(vector<int> posibileNumber)
    {
        for (int i = 0; i < posibileNumber.size(); i++)
        {
            cout << posibileNumber[i] << endl;
        }
    }
    void checkResult()
    {
        cout << "Solve Board" << endl;
        printBoardSolved();
        bool isValidate = true;
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                if (board[i][j] == boardSolved[i][j])
                {
                    cout << "\033[1;32m" << board[i][j] << "\033[0m"
                         << " ";
                }
                else if (j == i)
                {
                    isValidate = false;
                    cout << "\033[1;31m" << board[i][j] << "\033[0m"
                         << " ";
                }
            }
            cout << endl;
        }
        cout << (isValidate ? "Success" : "Error") << endl;
    }
    void testWhenResultError()
    {
        cout << "Error Board" << endl;
        printBoardError();
        bool isValidate = true;
        for (int i = 0; i < Sudoku::size; i++)
        {
            for (int j = 0; j < Sudoku::size; j++)
            {
                if (board[i][j] == boardError[i][j])
                {
                    cout << "\033[1;32m" << board[i][j] << "\033[0m"
                         << " ";
                }
                else if (j == i)
                {
                    isValidate = false;
                    cout << "\033[1;31m" << board[i][j] << "\033[0m"
                         << " ";
                }
            }
            cout << endl;
        }
        cout << (isValidate ? "Success" : "Error") << endl;
    }
    void runSudoku()
    {
        // clearBoard();
        //  readInput();
        print();
        cout << endl;
        solve(0, 0, 1);
        print();
    }
};
