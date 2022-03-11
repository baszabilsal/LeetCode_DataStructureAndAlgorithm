#include <bits/stdc++.h>
using namespace std;
int getMin(vector<vector<int>> &triangle, int i, int j)
{
    int size = triangle[i - 1].size();
    int minv = 0;
    if (j == size)
    {
        minv = triangle[i - 1][j - 1];
    }
    else if (j - 1 >= 0)
    {
        minv = min(triangle[i - 1][j], triangle[i - 1][j - 1]);
    }
    else
    {
        minv = triangle[i - 1][j];
    }
    return minv;
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int size = triangle.size();
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            triangle[i][j] += getMin(triangle, i, j);
        }
    }
    int minv = triangle[size - 1][0];
    for (int i = 1; i < triangle[size - 1].size(); i++)
    {
        minv = min(minv, triangle[size - 1][i]);
    }
    return minv;
}
int main()
{
    vector<vector<int>> a = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(a) << endl;
}