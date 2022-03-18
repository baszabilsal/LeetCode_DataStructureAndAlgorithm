#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    vector<int> raw;
    void solve(vector<vector<int>> &graph, int position)
    {
        if (graph[position].size() - 1 == 0)
        {
            output.push_back(raw);
            return;
        }
        for (int i = 0; i < graph[position].size(); i++)
        {
            raw.push_back(graph[position][i]);
            solve(graph, graph[position][i]);
            raw.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        raw.push_back(0);
        solve(graph, 0);
        return output;
    }
};
int main()
{
    Solution st;
    vector<vector<int>> grid = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> output = st.allPathsSourceTarget(grid);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}