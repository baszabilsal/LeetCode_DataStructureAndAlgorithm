#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    vector<int> v;
    void solve(vector<int> &candidates, int i, int sum, int target)
    {
        if (target == sum)
        {
            output.push_back(v);
            return;
        }
        if (i >= candidates.size() || target < sum)
        {
            return;
        }
        if (sum + candidates[i] <= target)
        {
            v.push_back(candidates[i]);
            solve(candidates, i + 1, sum + candidates[i], target);
            v.pop_back();
        }
        int temp = candidates[i];
        while (i < candidates.size() && candidates[i] == temp)
        {
            i++;
        }
        solve(candidates, i, sum, target);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, 0, target);
        return output;
    }
};
int main()
{

    vector<int> a = {1, 2, 2, 2, 5};
    Solution st;
    vector<vector<int>> output = st.combinationSum2(a, 5);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}