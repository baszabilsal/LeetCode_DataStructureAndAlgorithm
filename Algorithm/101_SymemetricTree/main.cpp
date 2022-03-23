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
    bool isValid(TreeNode *left, TreeNode *right)
    {
        bool isValid = false;
        if (left && right)
        {
            isValid = left->val == right->val;
        }
        else if (!left && !right)
        {
            isValid = true;
        }
        return isValid;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root)
        {
            stack<TreeNode *> sRight;
            stack<TreeNode *> sLeft;
            if (!isValid(root->left, root->right))
            {
                return false;
            }
            else if (root->right && root->left)
            {
                sRight.push(root->right);
                sLeft.push(root->left);
            }
            while (sRight.size() > 0 && sLeft.size())
            {
                TreeNode *left = sLeft.top();
                TreeNode *right = sRight.top();
                sLeft.pop();
                sRight.pop();
                if (!isValid(left, right))
                {
                    return false;
                }
                else
                {
                    if (!isValid(left->right, right->left))
                    {
                        return false;
                    }
                    else if (left->right && right->left)
                    {
                        sLeft.push(left->right);
                        sRight.push(right->left);
                    }
                    if (!isValid(left->left, right->right))
                    {
                        return false;
                    }
                    else if (left->left && right->right)
                    {
                        sLeft.push(left->left);
                        sRight.push(right->right);
                    }
                }
            }
            return sRight.size() == 0 && sLeft.size() == 0;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
}