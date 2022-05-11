#include <bits/stdc++.h>
#include "StringManipulation.h"

using namespace std;
StringManipulation st;
void getMainMenu();
void getSubMenu();
void runWithCString();
int readInputMainMenu();
int readInputSubMenu();
void runWithoutCString();
void runCompareTwoString(int option);
void runCompareTwoStringWithLength(int option);
void runCopiesString(int option);
void runCopiesStringWithLength(int option);
void runAppendString(int option);
void runAppendStringWithLength(int option);
void runTokenizes();
void runTokenizesWithOutLibrary();
void runFindLenghString(int option);
int main()
{
    bool isRunning = true;
    while (isRunning)
    {
        getMainMenu();
        int option = readInputMainMenu();
        switch (option)
        {
        case 1:
            runWithCString();
            break;
        case 2:
            runWithoutCString();
            break;
        case 3:
            isRunning = false;
            break;
        }
    }
    return 0;
}
void getMainMenu()
{
    cout << "\n\n Manipulation of strings using \n\n";
    cout << " 1. With or \n";
    cout << " 2. Without \n";
    cout << " 3. close programs \n";
}
void getSubMenu()
{
    cout << "\n\nYou have chosen to use the CSTRING \n\n";
    cout << " 1. Compare two strings \n";
    cout << " 2. Compares two strings up to a certain length \n";
    cout << " 3. Copies one string into another \n";
    cout << " 4. Copies one string into another up to a certain lenght \n";
    cout << " 5. Appends one string to another \n";
    cout << " 6. Appends one string to another up to a certain lengh \n";
    cout << " 7. Tokenizes and reveres the word in a string \n";
    cout << " 8. Finds the lengh of a string \n";
    cout << " 9. exist \n";
}
int readInputCompareStringMenu()
{
    int option;
    cin >> option;
    while (((option < 1) || (option > 5)) || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> option;
    }
    return option;
}
void getCompareStringMenu()
{
    cout << "\n\nYou have chosen to use the CSTRING \n\n";
    cout << " 1. Array/Subscript notation \n";
    cout << " 2. Pointer/Subscript notation\n";
    cout << " 3. Array/Offset notation \n";
    cout << " 4. Pointer/Offset notation \n";
    cout << " 5. exist \n";
    int option = readInputCompareStringMenu();
    switch (option)
    {
    case 1:
        runCompareTwoString(2);
        break;
    case 2:
        runCompareTwoString(3);
        break;
    case 3:
        runCompareTwoString(4);
        break;
    case 4:
        runCompareTwoString(5);
        break;
    }
}
int readInputMainMenu()
{
    int option;
    cin >> option;
    while (((option < 1) || (option > 3)) || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> option;
    }
    return option;
}
int readInputSubMenu()
{
    int option;
    cin >> option;
    while (((option < 1) || (option > 9)) || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> option;
    }
    return option;
}
void runWithCString()
{
    bool isRunning = true;
    while (isRunning)
    {
        getSubMenu();
        int option = readInputSubMenu();
        switch (option)
        {
        case 1:
            runCompareTwoString(1);
            break;
        case 2:
            runCompareTwoStringWithLength(1);
            break;
        case 3:
            runCopiesString(1);
            break;
        case 4:
            runCopiesStringWithLength(1);
            break;
        case 5:
            runAppendString(1);
            break;
        case 6:
            runAppendStringWithLength(1);
            break;
        case 7:
            runTokenizes();
            break;
        case 8:
            runFindLenghString(1);
            break;
        case 9:
            isRunning = false;
            break;
        }
    }
}

void runWithoutCString()
{
    bool isRunning = true;
    while (isRunning)
    {
        getSubMenu();
        int option = readInputSubMenu();
        switch (option)
        {
        case 1:
            getCompareStringMenu();
            break;
        case 2:
            runCompareTwoStringWithLength(2);
            break;
        case 3:
            runCopiesString(2);
            break;
        case 4:
            runCopiesStringWithLength(2);
            break;
        case 5:
            runAppendString(2);
            break;
        case 6:
            runAppendStringWithLength(2);
            break;
        case 7:
            runTokenizesWithOutLibrary();
            break;
        case 8:
            runFindLenghString(2);
            break;
        case 9:
            isRunning = false;
            break;
        }
    }
}
void runCompareTwoString(int option)
{
    char a[] = "a";
    char b[10] = "abbsdf";
    cout << "Compare two strings" << endl;
    cout << "input 1 : " << a << endl;
    cout << "input 2 : " << b << endl;
    int output = 0;
    switch (option)
    {
    case 1:
        cout << "with library " << endl;
        output = strcmp(b, a);
        break;
    case 2:
        cout << "without library  Array/Subscript notation" << endl;
        output = st.strcmpThatArraySubscriptionNotation(b, a);
        break;
    case 3:
        cout << "without library Pointer/Subscript notation" << endl;
        output = st.strcmpThatPointerSubscriptionNotation(b, a);
        break;
    case 4:
        cout << "without library Array/Offset notation" << endl;
        output = st.strcmpThatArrayOffsetnNotation(b, a);
        break;
    case 5:
        cout << "without library Pointer/Offset notation" << endl;
        output = st.strcmpThatPointerOffsetNotation(b, a);
        break;
    }
    cout << "output : " << output << endl;
}
void runCompareTwoStringWithLength(int option)
{
    char a[] = "ab bd aa123123";
    char b[10] = "ab ";
    size_t n = 10;
    cout << "Compare two strings with length " << endl;
    cout << "input 1 : " << a << endl;
    cout << "input 2 : " << b << endl;
    cout << "size : " << n << endl;
    int output = 0;
    switch (option)
    {
    case 1:
        cout << "with library " << endl;
        output = strncmp(b, a, n);
        break;
    case 2:
        cout << "without library " << endl;
        output = st.strncmp(b, a, n);
        break;
    }
    cout << "output : " << output << endl;
}
void runCopiesString(int option)
{
    char a[] = "ab bd aa";
    char b[10];
    cout << "Copies string " << endl;
    cout << "input : " << a << endl;
    switch (option)
    {
    case 1:
        cout << "with library " << endl;
        strcpy(b, a);
        break;
    case 2:
        cout << "without library " << endl;
        st.strcpy(b, a);
        break;
    }
    cout << "output : " << b << endl;
}
void runCopiesStringWithLength(int option)
{
    char a[] = "ab bd aa123123";
    cout << "Copies string with length" << endl;
    cout << "input : " << a << endl;
    char b[10];
    size_t n = 10;
    cout << "size : " << n << endl;
    switch (option)
    {
    case 1:
        cout << "with library " << endl;
        strncpy(b, a, n);
        break;
    case 2:
        cout << "without library " << endl;
        st.strncpy(b, a, n);
        break;
    }
    b[n] = '\0';
    cout << "output : " << b << endl;
}
void runAppendString(int option)
{
    char a[] = "ab bd aa";
    char b[10] = "yy";
    cout << "Append string " << endl;
    cout << "input 1: " << a << endl;
    cout << "input 2: " << b << endl;
    switch (option)
    {
    case 1:
        cout << "with library " << endl;
        strcat(b, a);
        break;
    case 2:
        cout << "without library " << endl;
        st.strcat(b, a);
        break;
    }
    cout << "output : " << b << endl;
}
void runAppendStringWithLength(int option)
{
    char a[] = "ab bd aa123123";
    char b[10] = "yy";
    size_t n = 10;
    cout << "Append string " << endl;
    cout << "input 1: " << a << endl;
    cout << "input 2: " << b << endl;
    cout << "size : " << n << endl;
    switch (option)
    {
    case 1:
        cout << "with library " << endl;
        strncat(b, a, n);
        break;
    case 2:
        cout << "without library " << endl;
        st.strncat(b, a, n);
        break;
    }
    b[n] = '\0';
    cout << "output : " << b << endl;
}
void runTokenizes()
{
    char a[] = "ab bd aa";
    cout << "run Tokenizes " << endl;
    cout << "input : " << a << endl;
    cout << "with library " << endl;
    char *o;
    o = strtok(a, " ");
    while (o != NULL)
    {
        cout << o << endl;
        o = strtok(NULL, " ");
    }
}
void runTokenizesWithOutLibrary()
{
    char a[] = "ab bd aa";
    cout << "run Tokenizes " << endl;
    cout << "input : " << a << endl;
    cout << "without library " << endl;
    cout << "output : " << endl;
    char *o;
    o = st.strtok(a, " ");
    while (o != NULL)
    {
        cout << o << endl;
        o = st.strtok(NULL, " ");
    }
}
void runFindLenghString(int option)
{
    char a[] = "ab bd aa";
    cout << "find length string " << endl;
    cout << "input : " << a << endl;
    char b[10];
    size_t l = 0;
    switch (option)
    {
    case 1:
        cout << "with library " << endl;
        l = strlen(a);
        break;
    case 2:
        cout << "without library " << endl;
        l = st.strlen(a);
        break;
    }
    cout << "output : " << l << endl;
}