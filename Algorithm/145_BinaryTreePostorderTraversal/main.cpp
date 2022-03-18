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
    vector<int> output;
    void solve(TreeNode *root)
    {
        if (root)
        {
            if (root->left)
            {
                solve(root->left);
            }
            if (root->right)
            {
                solve(root->right);
            }
            output.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        solve(root);
        return output;
    }
};
int main()
{
}