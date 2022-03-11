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

TreeNode *dfs(TreeNode *node, const TreeNode *node1, const TreeNode *node2)
{
    if ((node1 || node2))
    {
        int node1Val = 0;
        int node2Val = 0;
        TreeNode *node1Right = nullptr;
        TreeNode *node1Left = nullptr;
        TreeNode *node2Right = nullptr;
        TreeNode *node2Left = nullptr;
        if (node1)
        {
            node1Val = node1->val;
            node1Right = node1->right;
            node1Left = node1->left;
        }
        if (node2)
        {
            node2Val = node2->val;
            node2Right = node2->right;
            node2Left = node2->left;
        }
        node = new TreeNode(node2Val + node1Val);
        node->left = dfs(node->left, node1Left, node2Left);
        node->right = dfs(node->right, node1Right, node2Right);
    }
    return node;
}
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    TreeNode *node = nullptr;
    return dfs(node, root1, root2);
}
int main()
{
    TreeNode *root1;
    TreeNode *root2;
    mergeTrees(root1, root2);
    return 0;
}