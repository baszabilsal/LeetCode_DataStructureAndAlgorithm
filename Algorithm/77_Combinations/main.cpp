#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    void solve(int n, int k, int start, vector<int> track)
    {
        if (track.size() == k)
        {
            output.push_back(track);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            track.push_back(i);
            solve(n, k, i + 1, track);
            track.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> track;
        solve(n, k, 1, track);
        return output;
    }
};
int main()
{
    Solution st;
    int n = 4;
    int k = 2;
    vector<vector<int>> grid = st.combine(n, k);
}