#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert2(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> output;
        intervals.push_back(newInterval);
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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> output;
        bool isInserted = false;
        int l = newInterval[0];
        int r = newInterval[1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (!isInserted)
            {
                if (intervals[i][1] <= r && intervals[i][1] >= l && intervals[i][0] <= l)
                {
                    intervals[i][1] = r;
                    l = intervals[i][0];
                    isInserted = true;
                }
                else if (intervals[i][0] >= l && intervals[i][1] >= r && r >= intervals[i][0]) // 3,1  ,4,2
                {
                    intervals[i][0] = l;
                    r = intervals[i][1];
                    isInserted = true;
                }
                else if (intervals[i][0] >= l && intervals[i][1] <= r)
                {
                    intervals[i][0] = l;
                    intervals[i][1] = r;
                    isInserted = true;
                }
                else if (intervals[i][0] <= l && intervals[i][1] >= r)
                {
                    r = intervals[i][1];
                    l = intervals[i][0];
                    isInserted = true;
                }
                else if (r < intervals[i][0])
                {
                    output.push_back({l, r});
                    r = intervals[i][1];
                    l = intervals[i][0];
                    isInserted = true;
                }
                else
                {
                    output.push_back({intervals[i][0], intervals[i][1]});
                }
            }
            else
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
        }
        output.push_back({l, r});
        return output;
    }
};
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> insert = {2, 9};
    Solution st;
    intervals = st.insert(intervals, insert);
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