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
    TreeNode *solve(TreeNode *root, int p, int q)
    {
        if (!root)
            return root;
        if (root->val < p && root->val < q)
        {
            return solve(root->right, p, q);
        }
        else if (root->val > p && root->val > q)
        {
            return solve(root->left, p, q);
        }
        return root;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return solve(root, p->val, q->val);
    }
};
int main()
{
}