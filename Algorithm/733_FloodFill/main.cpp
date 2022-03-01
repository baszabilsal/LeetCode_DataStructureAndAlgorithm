#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &image, int sr, int sc, int newColor, int maxRow, int maxColumn, int sourceValue)
{
    if (sr < 0 || sr >= maxRow || sc < 0 || sc >= maxColumn || image[sr][sc] != sourceValue || image[sr][sc] == newColor) // break;
    {
        return;
    }
    image[sr][sc] = newColor;
    solve(image, sr, sc + 1, newColor, maxRow, maxColumn, sourceValue);
    solve(image, sr + 1, sc, newColor, maxRow, maxColumn, sourceValue);
    solve(image, sr - 1, sc, newColor, maxRow, maxColumn, sourceValue);
    solve(image, sr, sc - 1, newColor, maxRow, maxColumn, sourceValue);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int maxRow = image.size();
    int maxColumn = image[0].size();
    int sourceValue = image[sr][sc];
    solve(image, sr, sc, newColor, maxRow, maxColumn, sourceValue);
    return image;
}
int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sc = 1;
    int sr = 1;
    int newColor = 1;
    int maxRow = image.size();
    int maxColumn = image[0].size();
    image = floodFill(image, sr, sc, newColor);
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxColumn; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}