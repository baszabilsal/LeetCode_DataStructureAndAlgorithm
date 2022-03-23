#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0];
        int r = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][1] >= r && intervals[i][0] <= r)
            {
                r = intervals[i][1];
            }
            else if (intervals[i][0] > r)
            {
                output.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        output.push_back({l, r});
        return output;
    }
};
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {5, 10}, {15, 18}};
    Solution st;
    intervals = st.merge(intervals);
    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals[i].size(); j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << endl;
    }
    {
        /* code */
    }

    return 0;
}