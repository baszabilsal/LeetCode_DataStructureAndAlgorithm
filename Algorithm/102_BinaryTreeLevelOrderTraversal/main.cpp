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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> output;
        if (root)
        {
            queue<TreeNode *> q;
            q.push(root);
            while (q.size() > 0)
            {
                int count = q.size();
                vector<int> raw;
                while (count--)
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
                    raw.push_back(node->val);
                }
                output.push_back(raw);
            }
        }
        return output;
    }
};
int main()
{
}