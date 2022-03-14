#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> output;
    vector<int> v;
    int sum = 0;
    void solve(vector<int> &candidates, int i, int target)
    {
        if (target == sum)
        {
            output.push_back(v);
            return;
        }
        if (i >= candidates.size() || candidates[i] > target)
        {
            return;
        }
        if (sum + candidates[i] <= target)
        {
            sum += candidates[i];
            v.push_back(candidates[i]);
            solve(candidates, i, target);
            sum -= candidates[i];
            v.pop_back();
        }
        solve(candidates, i + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target);
        return output;
    }
};
int main()
{

    vector<int> a = {2, 3, 5, 7};
    Solution st;
    vector<vector<int>> output = st.combinationSum(a, 7);
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