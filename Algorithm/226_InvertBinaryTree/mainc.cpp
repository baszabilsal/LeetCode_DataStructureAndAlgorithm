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
    void solve(TreeNode *node)
    {
        if (node)
        {
            TreeNode *temp = node->right;
            node->right = node->left;
            node->left = temp;
            solve(node->right);
            solve(node->left);
        }
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            solve(root);
        }
        return root;
    }
};
int main()
{

    return 0;
}