#include <bits/stdc++.h>
using namespace std;
bool solve(vector<long> &printer1, vector<long> &printer2, vector<long> &printer3, vector<long> &output)
{
    long total = 0;
    for (int i = 0; i < 4; i++)
    {
        long minInk = min(printer1[i], printer2[i]);
        minInk = min(minInk, printer3[i]);
        output[i] = minInk;
        total += minInk;
    }
    return total >= 1000000;
}
int main()
{
    int t;
    cin >> t;
    int count = 1;
    while (t--)
    {
        vector<long> printer1;
        vector<long> printer2;
        vector<long> printer3;
        vector<long> output = {0, 0, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            long input;
            cin >> input;
            printer1.push_back(input);
        }
        for (int i = 0; i < 4; i++)
        {
            long input;
            cin >> input;
            printer2.push_back(input);
        }
        for (int i = 0; i < 4; i++)
        {
            long input;
            cin >> input;
            printer3.push_back(input);
        }
        bool isPossible = solve(printer1, printer2, printer3, output);
        cout << "Case #" << count << ": ";
        if (isPossible)
        {
            long total = 0;
            for (int i = 0; i < 4; i++)
            {
                if (total + output[i] <= 1000000)
                {
                    total += output[i];
                    cout << output[i] << " ";
                }
                else
                {
                    output[i] = 1000000 - total;
                    total = 1000000;
                    cout << output[i] << " ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
        count++;
    }
}