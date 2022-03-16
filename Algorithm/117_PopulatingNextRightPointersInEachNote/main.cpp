#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *output = new Node();
        Node *temp = output;
        queue<Node *> st;
        if (root)
        {
            st.push(root);
        }
        while (st.size())
        {
            int count = st.size();
            int tempCount = count;
            while (count > 0)
            {
                Node *raw = st.front();
                st.pop();
                if (raw->left)
                {
                    st.push(raw->left);
                }
                if (raw->right)
                {
                    st.push(raw->right);
                }
                if (tempCount == count)
                {
                    temp->right = new Node(raw->val);
                    temp = temp->right;
                }
                else
                {
                    temp->next = new Node(raw->val);
                    temp = temp->next;
                }
                count--;
            }
        }
        return output->right;
    }
};
int main()
{
}