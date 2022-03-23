#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    map<int, int> m;
    bool solve(TreeNode *root, int k)
    {
        if (root)
        {

            if (m.find(root->val) != m.end())
            {
                return true;
            }
            m[k - root->val]++;
            if (solve(root->left, k))
            {
                return true;
            }
            return solve(root->right, k);
        }
        return false;
    }
    bool findTarget(TreeNode *root, int k)
    {
        return solve(root, k);
    }
};
int main()
{
}