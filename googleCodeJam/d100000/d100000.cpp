#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &dices)
{
    sort(dices.begin(), dices.end());
    int r = dices.size();
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        if (dices[i] > count)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    int count = 1;
    while (t--)
    {
        int size;
        cin >> size;
        vector<int> dices;
        for (int i = 0; i < size; i++)
        {
            int input;
            cin >> input;
            dices.push_back(input);
        }
        cout << "Case #" << count << ": ";
        cout << solve(dices) << endl;
        count++;
    }
}