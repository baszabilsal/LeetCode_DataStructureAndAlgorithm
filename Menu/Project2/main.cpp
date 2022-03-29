#include <bits/stdc++.h>
#define n 8
using namespace std;

#define size 9
// const int size= 9;

const int NUMBER_OF_QUEENS = 8;
int queens[NUMBER_OF_QUEENS], NO;
void printResult(int NUMBER_OF_QUEENS);

// ALL CODE in EightQueen Project

bool isValid(int row, int column)
{
    for (int i = 1; i <= row - 1; i++)
        if (queens[i] == column               // Check column
            || queens[row - i] == column - i  // Check upper left diagonal
            || queens[row - i] == column + i) // Check upper right diagonal
            return false;                     // There is a conflict
    return true;                              // No conflict
}
////////////////////////////////////////////////////////////////////////////////////////////
void nQueens(int row, int NUMBER_OF_QUEENS)
{

    for (int i = 1; i <= NUMBER_OF_QUEENS; i++)
    {
        if (isValid(row, i))
        {
            queens[row] = i;
            if (row == NUMBER_OF_QUEENS)
                printResult(NUMBER_OF_QUEENS);
            else
                nQueens(row + 1, NUMBER_OF_QUEENS);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
void printResult(int NUMBER_OF_QUEENS)
{
    cout << "Solution No. " << ++NO << endl;
    for (int column = 1; column <= NUMBER_OF_QUEENS; column++)
    {
        for (int j = 1; j <= NUMBER_OF_QUEENS; j++)
        {
            if (queens[column] != j)
                cout << "| ";
            else
                cout << "| Q ";
        }
        cout << endl;
    }
}

// ALL CODE in KnightTour Project

bool valid(int nx, int ny, int mat[n][n])
{
    return (nx >= 0 and nx < n and ny >= 0 and ny < n and mat[nx][ny] == -1);
}
////////////////////////////////////////////////////////////////////////////
bool go(int mat[n][n], int x, int y, int mv, int dx[n], int dy[n])
{
    if (mv == n * n)
    {
        return 1;
    }

    for (int k = 0; k < 8; k++)

    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (valid(nx, ny, mat))
        {
            mat[nx][ny] = mv;
            if (go(mat, nx, ny, mv + 1, dx, dy) == 1)
            {
                return 1;
            }
            mat[nx][ny] = -1; // fill with -1
        }
    }
    return 0;
}

// ALL CODE in Sodoku Project
int getFreeCellList(int grid[][size], int freeCellList[][2])
{
    // 81 is the maximum number of free cells
    int numberOfFreeCells = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (grid[i][j] == 0)
            {
                freeCellList[numberOfFreeCells][0] = i;
                freeCellList[numberOfFreeCells][1] = j;
                numberOfFreeCells++;
            }

    return numberOfFreeCells;
}

///////////////////////////////////////////////////////////////////////////////////////
/** Print the values in the grid */
void printGrid(int grid[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////
/** Check whether grid[i][j] is valid in the grid */
bool isValid(int i, int j, int grid[][size])
{
    // Check whether grid[i][j] is valid at the i's row
    for (int column = 0; column < size; column++)
        if (column != j && grid[i][column] == grid[i][j])
            return false;

    // Check whether grid[i][j] is valid at the j's column
    for (int row = 0; row < size; row++)
        if (row != i && grid[row][j] == grid[i][j])
            return false;

    // Check whether grid[i][j] is valid in the 3 by 3 box
    for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
        for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
            if (row != i && col != j && grid[row][col] == grid[i][j])
                return false;

    return true; // The current value at grid[i][j] is valid
}

///////////////////////////////////////////////////////////////////////////////////////
/** Search for a solution */
bool search(int grid[][size])
{
    int k = 0;          // Start from the first free cell
    bool found = false; // Solution found?

    int freeCellList[81][2];
    int numberOfFreeCells = getFreeCellList(grid, freeCellList);

    while (!found)
    {
        int i = freeCellList[k][0];
        int j = freeCellList[k][1];
        if (grid[i][j] == 0)
            grid[i][j] = 1; // Start with 1

        if (isValid(i, j, grid))
        {
            if (k + 1 == numberOfFreeCells)
            {                 // No more free cells
                found = true; // A solution is found
            }
            else
            { // Move to the next free cell
                k++;
            }
        }
        else if (grid[i][j] < size)
        {
            grid[i][j] = grid[i][j] + 1; // Check the next possible value
        }
        else
        { // grid[i][j] is 9, backtrack
            while (grid[i][j] == size)
            {
                grid[i][j] = 0; // Reset to free cell
                if (k == 0)
                {
                    return false; // No possible value
                }
                k--; // Backtrack
                i = freeCellList[k][0];
                j = freeCellList[k][1];
            }

            grid[i][j] = grid[i][j] + 1; // Check the next possible value
        }
    }

    return true; // A solution is found
}

////////////////////////////////////////////////////////////////////////////////
bool Range(int grid[][size])
{
    // Check for duplicate numbers
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (grid[i][j] != 0)
                if (!isValid(i, j, grid))
                    return false;

    // Check whether numbers are in the range
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if ((grid[i][j] < 0) || (grid[i][j] > size))
                return false;

    return true; // The fixed cells are valid
}
///////////////////////////////////////////////////////////////////////////////////

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
void runEightQueen() //  Main Function of EightQueen
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Eight Queen Problem\n\n";

    {
        nQueens(8, NUMBER_OF_QUEENS);
    }
    cout << "\n\n*********************************************************************************************************************" << endl;
}
void runKnightTour() //  Main Function of KnightTour
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Knight Tour Problem\n\n";

    int mat[n][n];
    memset(mat, -1, sizeof(mat)); // fill metrix with -1
    mat[0][0] = 0;                // first Move
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    if (go(mat, 0, 0, 1, dx, dy))

    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << "\t";
            cout << endl;
        }
        cout << "\n\n*********************************************************************************************************************" << endl;
    }
}
void runSudoku() // Main Function of Sudoku
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    int grid[size][size] = {{0, 4, 0, 0, 0, 0, 1, 7, 9},
                            {0, 0, 2, 0, 0, 8, 0, 5, 4},
                            {0, 0, 6, 0, 0, 5, 0, 0, 8},
                            {0, 8, 0, 0, 7, 0, 9, 1, 0},
                            {0, 5, 0, 0, 9, 0, 0, 3, 0},
                            {0, 1, 9, 0, 6, 0, 0, 4, 0},
                            {3, 0, 0, 4, 0, 0, 7, 0, 0},
                            {5, 7, 0, 1, 0, 0, 2, 0, 0},
                            {9, 2, 8, 0, 0, 0, 0, 6, 0}};

    if (!Range(grid))
        cout << "Invalid input" << endl;

    else if (search(grid))
    {
        cout << " The soulution found:" << endl;
        printGrid(grid);
    }
    else
        cout << "no solution" << endl;
}