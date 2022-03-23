#include <bits/stdc++.h>
#include "backtracking/eightQueen/eightQueen.h"
#include "backtracking/knightTour/knightTour.h"
#include "backtracking/sudoku/sudoku.h"
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
    while (isRunning)
    {
        getMainMenu();
        int option = readInputMainMenu();
        if (option == 2)
        {
            isRunning = false;
        }
        else
        {
            runBackTrackingMenu();
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
    while (isRunning)
    {
        getBackTrackingMenu();
        int option = readInputBackTrackingMenu();
        switch (option)
        {
        case 1:
            runEightQueen();
            break;
        case 2:
            runKnightTour();
            break;
        case 3:
            runSudoku();
            break;
        case 4:
            isRunning = false;
            break;
        }
    }
}
void runEightQueen()
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Eight Queen Problem\n\n";
    EightQueen eightQueen;
    eightQueen.runEightQueen();
    cout << "\n\n*********************************************************************************************************************" << endl;
}
void runKnightTour()
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Knight Tour Problem\n\n";

    KnightTour knightTour;
    knightTour.runKnightTour();
    cout << "\n\n*********************************************************************************************************************" << endl;
}
void runSudoku()
{
    cout << "\n\n*********************************************************************************************************************" << endl;
    cout << "Sudoku Problem\n\n";

    Sudoku sudoku;
    sudoku.runSudoku();
    cout << "\n\n*********************************************************************************************************************" << endl;
}