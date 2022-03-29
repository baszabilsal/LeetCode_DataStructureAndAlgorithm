#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int minV = intervals[0][0];
        int maxV = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (minV <= intervals[i][0] && intervals[i][0] < maxV)
            {
                count++;
                if (maxV > intervals[i][1])
                {
                    minV = intervals[i][0];
                    maxV = intervals[i][1];
                }
            }
            else
            {
                minV = intervals[i][0];
                maxV = intervals[i][1];
            }
        }
        return count;
    }
};
int main()
{
    Solution st;
    vector<vector<int>> a = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << st.eraseOverlapIntervals(a) << endl;
}