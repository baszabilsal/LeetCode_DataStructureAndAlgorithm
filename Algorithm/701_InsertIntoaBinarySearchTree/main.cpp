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
    void solve(TreeNode *root, int val)
    {

        if (root)
        {
            if (root->val < val)
            {
                if (root->right)
                {
                    solve(root->right, val);
                }
                else
                {
                    root->right = new TreeNode(val);
                }
            }
            else
            {
                if (root->left)
                {
                    solve(root->left, val);
                }
                else
                {
                    root->left = new TreeNode(val);
                }
            }
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root)
        {
            solve(root, val);
        }
        else
        {
            root = new TreeNode(val);
        }
        return root;
    }
};
int main()
{

    return 0;
}