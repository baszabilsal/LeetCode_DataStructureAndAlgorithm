#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        reverse(digits.begin(), digits.end());
        digits[0]++;
        int add = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            digits[i] = digits[i] + add;
            add = 0;
            if (digits[i] == 10)
            {
                digits[i] = 0;
                add = 1;
            }
        }
        if (add == 1)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
int main()
{
    Solution st;
    vector<int> obstacleGrid = {1, 2, 3};
    obstacleGrid = st.plusOne(obstacleGrid);
    for (int i = 0; i < obstacleGrid.size(); i++)
    {
        cout << obstacleGrid[i] << " ";
    }
    cout << endl;
    return 0;
}