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
    bool validateSubRoot(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        else if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        if (root->val == subRoot->val &&
            validateSubRoot(root->left, subRoot->left) &&
            validateSubRoot(root->right, subRoot->right))
        {
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->val == subRoot->val && validateSubRoot(root, subRoot))
        {
            return true;
        }
        else if (isSubtree(root->right, subRoot))
        {
            return true;
        }
        else if (isSubtree(root->left, subRoot))
        {
            return true;
        }
        return false;
    }
};
int main()
{
}