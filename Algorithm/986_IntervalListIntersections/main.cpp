#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> _firstList;
    vector<vector<int>> _secondList;
    vector<vector<int>> output;
    void solve(int i, int j)
    {
        cout << " in : " << i << " " << j << endl;
        if (i >= _firstList.size() || j >= _secondList.size())
        {
            return;
        }
        int maxFirst = _firstList[i][1];
        int minFirst = _firstList[i][0];
        int minSecond = _secondList[j][0];
        int maxSecond = _secondList[j][1];
        if (minFirst <= maxSecond && minSecond <= minFirst)
        {
            if (maxSecond > maxFirst)
            {
                output.push_back({minFirst, maxFirst});
            }
            else
            {
                output.push_back({minFirst, maxSecond});
            }
        }
        if (maxFirst >= minSecond && minSecond >= minFirst)
        {
            if (maxSecond < maxFirst)
            {
                output.push_back({minSecond, maxSecond});
            }
            else
            {
                output.push_back({minSecond, maxFirst});
            }
        }
        if (i >= _firstList.size())
        {
            solve(i, j + 1);
        }
        else if (j >= _secondList.size())
        {
            solve(i + 1, j);
        }
        else if (maxSecond > maxFirst)
        {
            cout << " inMax1 : " << endl;
            solve(i + 1, j);
        }
        else if (maxSecond < maxFirst)
        {
            cout << " inMax2 : " << endl;
            solve(i, j + 1);
        }
        else
        {
            cout << " inMax3 : " << endl;
            solve(i + 1, j + 1);
        }
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        _firstList = firstList;
        _secondList = secondList;
        solve(0, 0);
        return output;
    }
};
int main()
{
    vector<vector<int>> a = {{3, 5}, {9, 20}};
    vector<vector<int>> b = {{4, 5}, {7, 10}, {11, 12}, {14, 15}, {16, 20}};
    Solution st;
    vector<vector<int>> c = st.intervalIntersection(a, b);
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i][0] << " " << c[i][1] << endl;
    }
}