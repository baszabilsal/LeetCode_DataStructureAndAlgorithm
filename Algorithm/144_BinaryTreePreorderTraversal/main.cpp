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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> output;
        if (root)
        {
            stack<TreeNode *> st;
            st.push(root);
            while (st.size() > 0)
            {
                TreeNode *node = st.top();
                st.pop();
                output.push_back(node->val);
                if (node->right)
                {
                    st.push(node->right);
                }
                if (node->left)
                {
                    st.push(node->left);
                }
            }
        }
        return output;
    }
};
int main()
{
}