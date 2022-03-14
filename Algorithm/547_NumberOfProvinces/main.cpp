#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void clear(int *province, int position, vector<vector<int>> &isConnected)
    {
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (i != position && isConnected[position][i] == 1 && province[i] == 0)
            {
                province[i] = 1;
                clear(province, i, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int numberProvince = isConnected.size();
        int province[200] = {};
        int count = 0;
        for (int i = 0; i < numberProvince; i++)
        {
            if (province[i] == 0)
            {
                count++;
                clear(province, i, isConnected);
            }
        }
        return count;
    }
};
int main()
{
    Solution st;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    cout << st.findCircleNum(image) << endl;
    return 0;
}