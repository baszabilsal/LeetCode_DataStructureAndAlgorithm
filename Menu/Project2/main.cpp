#include <bits/stdc++.h>
using namespace std;
void getMainMenu();
void getBackTrackingMenu();
void runEightQueen();
void runKnightTour();
void runSudoku();
int readInputMainMenu();
void runBackTrackingMenu();
int main()
{
    bool isRunning = true;
    while (isRunning) // while loop program still running when isRunning = true
    {
        getMainMenu();                    // display main menu
        int option = readInputMainMenu(); // get input and set to option
        if (option == 2)                  // option = 2 for exist program
        {
            isRunning = false;
        }
        else
        {
            runBackTrackingMenu(); // when should option = 1 it will go to submenu backtracking
        }
    }
    return 0;
}
void getMainMenu()
{
    cout << "\n\nSelect folder..\n\n";
    cout << " 1. backTracking algorithm \n";
    cout << " 2. close programs \n";
}
void getBackTrackingMenu()
{
    cout << "\n\nSelect project backtracking algorithm..\n\n";
    cout << " 1. eight queen problem \n";
    cout << " 2. knight tour problem \n";
    cout << " 3. sudoku problem \n";
    cout << " 4. exist \n";
}
int readInputMainMenu()
{
    int option;
    cin >> option;
    while (((option < 1) || (option > 2)) || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> option;
    }
    return option;
}
int readInputBackTrackingMenu()
{
    int option;
    cin >> option;
    while (((option < 1) || (option > 4)) || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> option;
    }
    return option;
}
void runBackTrackingMenu()
{
    bool isRunning = true;
    while (isRunning) // it's same main menu
    {
        getBackTrackingMenu();                    // display menu
        int option = readInputBackTrackingMenu(); // get input and set to option
        switch (option)
        {
        case 1:
            runEightQueen(); // option = 1 for run project eight queen
            break;
        case 2:
            runKnightTour(); // option = 2 for run project knigh tour
            break;
        case 3:
            runSudoku(); // option = 3 for run project sudoku
            break;
        case 4:
            isRunning = false; // option = 4 for exist menu
            break;
        }
    }
}
void runEightQueen() // u should change your main function in eight queen project to this name
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Eight Queen Problem\n\n";
    Board board;
    board.setDefault();
    board.SetDefaultPostion();
    board.processParseQueen();
    board.printAllSolution();
    cout << "\n\n*********************************************************************************************************************" << endl;
}
void runKnightTour() //  u should change your main function in knight project to this name
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Knight Tour Problem\n\n";

    KnightTour knightTour;
    knightTour.runKnightTour();
    cout << "\n\n*********************************************************************************************************************" << endl;
}
void runSudoku() //  u should change your main function in sudoku project to this name
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Sudoku Problem\n\n";
    Sudoku sudoku;
    sudoku.runSudoku();
    cout << "\n\n*********************************************************************************************************************" << endl;
}

// ALL CODE in EightQueen Project
class Solution
{
public:
    vector<int> positions;
    int loop;
};
class Queen
{
public:
    int positions;
    bool isWork;
};
class Board
{
public:
    static const int totalQueen = 8;
    int posistion[totalQueen] = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<Solution> solutionList;

private:
    int board[totalQueen][totalQueen];

public:
    void print()
    {
        for (int i = 0; i < totalQueen; i++)
        {
            for (int j = 0; j < totalQueen; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    void setDefault()
    {
        for (int i = 0; i < totalQueen; i++)
        {
            for (int j = 0; j < totalQueen; j++)
            {
                board[i][j] = 0;
            }
        }
    }
    vector<Queen> GetSafeZone(int column)
    {
        vector<Queen> safeZone;
        for (int i = 0; i < totalQueen; i++)
        {
            if (board[i][column] == 0)
            {
                Queen q;
                q.positions = i;
                q.isWork = true;
                safeZone.push_back(q);
            }
        }
        return safeZone;
    }
    void insertQueen(int row, int column)
    {
        board[row][column] = 2;
        disableAreaWhenSetQueen(row, column);
    }
    void disableAreaWhenSetQueen(int row, int column)
    {
        for (int i = 0; i < totalQueen; i++)
        {
            if (board[row][i] == 0)
            {
                board[row][i] = 1;
            }
            if (board[i][column] == 0)
            {
                board[i][column] = 1;
            }
            if (board[row - i][column + i] == 0 && 0 <= row - i && row - i <= totalQueen && 0 <= column + i && column + i <= totalQueen)
            {
                board[row - i][column + i] = 1;
            }
            if (board[row + i][column + i] == 0 && 0 <= row + i && row + i <= totalQueen && 0 <= column + i && column + i <= totalQueen)
            {
                board[row + i][column + i] = 1;
            }
            if (board[row - i][column + i] == 0 && 0 <= row - i && row - i <= totalQueen && 0 <= column + i && column + i <= totalQueen)
            {
                board[row - i][column + i] = 1;
            }
            if (board[row - i][column - i] == 0 && 0 <= row - i && row - i <= totalQueen && 0 <= column - i && column - i <= totalQueen)
            {
                board[row - i][column - i] = 1;
            }
        }
    }
    void processParseQueen()
    {
        int count = 0;
        vector<Queen> postionQueen[totalQueen];
        postionQueen[0] = GetSafeZone(0);
        bool isProgramRun = true;
        for (int column = 0; column < totalQueen; column++)
        {
            count++;
            bool isProcess = false;
            if (postionQueen[column].size() > 0)
            {
                bool isBreak = false;
                for (int i = 0; i < postionQueen[column].size() && !isBreak; i++)
                {
                    if (postionQueen[column][i].isWork)
                    {
                        postionQueen[column][i].isWork = false;
                        posistion[column] = postionQueen[column][i].positions + 1;
                        SetQueen();
                        // print();
                        if (column + 1 < totalQueen)
                        {
                            postionQueen[column + 1] = GetSafeZone(column + 1);
                        }
                        isBreak = true;
                        isProcess = true;
                    }
                }
            }
            if (!isProcess)
            {
                if (column == 0)
                {
                    break;
                }
                else
                {
                    posistion[column - 1] = 0;
                    column = column - 2;
                    SetQueen();
                }
            }
            else if (column + 1 == totalQueen)
            {
                solutionList.push_back(getSolution(count));
                // print();
                posistion[column - 1] = 0;
                posistion[column] = 0;
                column = column - 2;
                SetQueen();
            }
        }
    }
    void SetQueen()
    {
        setDefault();
        for (int j = 0; j < totalQueen; j++)
        {
            if (posistion[j] > 0)
            {
                insertQueen(posistion[j] - 1, j);
            }
        }
    }
    void SetDefaultPostion()
    {
        for (int i = 0; i < totalQueen; i++)
        {
            posistion[i] = 0;
        }
    }
    void printPosition()
    {
        cout << endl
             << "postion : ";
        for (int i = 0; i < totalQueen; i++)
        {
            cout << posistion[i] << ",";
        }
        cout << endl;
    }
    Solution getSolution(int loop)
    {
        Solution solution;
        solution.loop = loop;
        for (int i = 0; i < totalQueen; i++)
        {
            solution.positions.push_back(posistion[i]);
        }
        return solution;
    }
    void printAllSolution()
    {
        for (int i = 0; i < solutionList.size(); i++)
        {
            cout << "solution  " << i + 1 << " from loop number " << solutionList[i].loop << " : ";
            for (int j = 0; j < solutionList[i].positions.size(); j++)
            {
                cout << solutionList[i].positions[j] << ",";
            }
            cout << endl;
        }
    }
};

// ALL CODE in KnightTour Project

class KnightTour
{
public:
    const static int boardSize = 8;

public:
    bool isPositonCanTour(int x, int y)
    {
        return (x >= 0 && x < boardSize && y >= 0 && y < boardSize && board[x][y] == 0);
    }
    void setDefaultBoard()
    {
        for (int i = 0; i < KnightTour::boardSize; i++)
        {
            for (int j = 0; j < KnightTour::boardSize; j++)
            {
                board[i][j] = 0;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < KnightTour::boardSize; i++)
        {
            for (int j = 0; j < KnightTour::boardSize; j++)
            {
                cout << " " << setw(2) << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool tour(int xPosition, int yPosition, int loop)
    {
        int knightMove, xNextPosition, yNextPosition;
        if (loop == KnightTour::boardSize * KnightTour::boardSize)
        {
            return true;
        }

        for (knightMove = 0; knightMove < 8; knightMove++)
        {
            xNextPosition = xPosition + xPositionKnightMove[knightMove];
            yNextPosition = yPosition + yPositionKnightMove[knightMove];
            if (isPositonCanTour(xNextPosition, yNextPosition))
            {
                board[xNextPosition][yNextPosition] = loop;
                if (tour(xNextPosition, yNextPosition, loop + 1))
                {
                    return true;
                }
                else
                {
                    // back tracking
                    board[xNextPosition][yNextPosition] = 0;
                }
            }
        }
        return false;
    }
    void solve()
    {
        if (tour(0, 0, 1))
        {
            cout << " Result : " << endl;
            print();
        }
        else
        {
            print();
            cout << "it not work" << endl;
        }
    }
    void runKnightTour()
    {
        setDefaultBoard();
        solve();
    }

public:
    int board[KnightTour::boardSize][KnightTour::boardSize];
    int xPositionKnightMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yPositionKnightMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
};

// ALL CODE in Sodoku Project
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