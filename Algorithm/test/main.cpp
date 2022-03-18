#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c, k, s = 1;                 // declare n,c,k and s = 1;
    cout << "\n Enter Number of Rows:"; // print string
    cin >> n;                           // read input and store in n
    s = n - 1;                          // set s = n -1; it's mean if n = 3 then s = 2;
    for (k = 1; k <= n; k++)            // loop n times start with k = 1 end when k = n if n = 3 then run loop 3 times
    {
        for (c = 1; c <= s; c++) // loop for push spacebar to console it's depend on s
        {
            cout << " ";
        }
        s--;                               // s decrease 1 every k + 1
        for (c = 1; c <= (2 * k) - 1; c++) // loop for push * to console it's depend on k every k times * increase 2
        {
            cout << "*";
        }
        cout << "\n"; // print new line;
    }
    // example n = 3, s= 2
    // loop k = 1, s= 2 first for loop is spacebar 2 times and second loop is * 1 times
    // loop k = 2, s= 1 first for loop is spacebar 1 times and second loop is * 3 times
    // loop k = 3, s= 0 first for loop is spacebar 0 times and second loop is * 5 times
    /* output is the

       *
      ***
     *****

     */
    s = 1;                       // set s = 1;
    for (k = 1; k <= n - 1; k++) // loop n-1 times start with k = 1 end when k = n-1 if n = 3 then run loop 2 times
    {
        for (c = 1; c <= s; c++) // loop for push spacebar to console it's depend on s
        {
            cout << " ";
        }
        s++;                                   // s increate 1 every k + 1
        for (c = 1; c <= 2 * (n - k) - 1; c++) // loop for push * to console it's depend on k every k times * decrease 2
        {
            cout << "*";
        }
        cout << "\n"; // print new line;
    }
    // example n = 3, s= 1
    // loop k = 1, s= 2 first for loop is spacebar 1 times and second loop is * 3 times
    // loop k = 2, s= 3 first for loop is spacebar 2 times and second loop is * 1 times
    /* output is the

     ***
      *

     */

    /*output or program when set input = 4
           *
          ***
         *****
        *******
         *****
          ***
           * 
    /*

}