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
    int maxDepth(TreeNode *root)
    {
        int count = 0;
        if (root)
        {
            queue<TreeNode *> q;
            q.push(root);
            while (q.size() > 0)
            {
                int s = q.size();
                while (s--)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
                count++;
            }
        }
        return count;
    }
};
int main()
{
}