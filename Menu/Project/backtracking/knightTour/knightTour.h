#include <bits/stdc++.h>
using namespace std;
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
