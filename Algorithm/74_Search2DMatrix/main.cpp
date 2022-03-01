#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l = 0;
    int xSize = matrix[0].size();
    int ySize = matrix.size();
    int totalSize = xSize * ySize;
    int r = totalSize;
    bool isFind = false;
    while (l < r)
    {
        int med = (l + r) / 2;
        int y = med / xSize;
        int x = med % xSize;
        r = r == totalSize ? totalSize - 1 : r;
        int yR = r / xSize;
        int xR = r % xSize;
        int yL = l / xSize;
        int xL = l % xSize;
        if (matrix[y][x] == target || matrix[yR][xR] == target || matrix[yL][xL] == target)
        {
            isFind = true;
            break;
        }
        else if (matrix[y][x] > target)
        {
            r = med;
        }
        else if (matrix[y][x] < target)
        {
            l = med + 1;
        }
    }
    return isFind;
}
int main()
{
    vector<int> a = {1, 3, 5, 7};
    vector<int> b = {10, 11, 16, 20};
    vector<int> c = {23, 30, 34, 60};
    vector<vector<int>> input;
    input.push_back(a);
    input.push_back(b);
    input.push_back(c);
    cout << searchMatrix(input, 3) << endl;
    return 0;
}