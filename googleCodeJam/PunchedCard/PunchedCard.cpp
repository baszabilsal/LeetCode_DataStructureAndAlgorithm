#include <bits/stdc++.h>
using namespace std;
vector<string> firstMatrix()
{
    return {{"..+-+"}, {"..|.|"}, {"+-+-+"}, {"|.|.|"}, {"+-+-+"}};
}
int main()
{
    int t;
    cin >> t;
    int count = 1;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        vector<string> matrix = firstMatrix();
        if (y > 2)
        {
            for (int j = 2; j < y; j++)
            {
                matrix[0] += "-+";
                matrix[1] += ".|";
                matrix[2] += "-+";
                matrix[3] += ".|";
                matrix[4] += "-+";
            }
        }
        if (x > 2)
        {
            for (int i = 2; i < x; i++)
            {
                matrix.push_back(matrix[3]);
                matrix.push_back(matrix[4]);
            }
        }
        cout << "Case #" << count << ":" << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            cout << matrix[i] << endl;
        }
        count++;
    }
}