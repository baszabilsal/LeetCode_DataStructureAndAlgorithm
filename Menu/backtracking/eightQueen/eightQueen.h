#include <bits/stdc++.h>
using namespace std;
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
class EightQueen
{
public:
    void runEightQueen()
    {
        Board board;
        board.setDefault();
        board.SetDefaultPostion();
        board.processParseQueen();
        board.printAllSolution();
    }
};
