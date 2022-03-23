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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root)
        {
            stack<TreeNode *> st;
            st.push(root);
            while (st.size())
            {
                TreeNode *node = st.top();
                st.pop();
                if (node->val == val)
                {
                    return node;
                }
                else
                {
                    if (node->left)
                    {
                        st.push(node->left);
                    }
                    if (node->right)
                    {
                        st.push(node->right);
                    }
                }
            }
        }
        return {};
    }
};
int main()
{

    return 0;
}