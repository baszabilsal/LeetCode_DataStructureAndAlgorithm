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
    bool solve(TreeNode *node, long min, long max)
    {
        if (!node)
            return true;
        if (node->val <= min || node->val >= max)
            return false;
        if (node->right)
        {
            bool isValid = solve(node->right, node->val, max);
            if (!isValid)
            {
                return false;
            }
        }
        if (node->left)
        {
            bool isValid = solve(node->left, min, node->val);
            if (!isValid)
            {
                return false;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
int main()
{
    return 0;
}