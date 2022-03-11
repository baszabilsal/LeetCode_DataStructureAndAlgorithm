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
Node *connect(Node *root)
{
    if (!root || !root->left)
        return root;                // if given empty tree OR root is leaf node
    root->left->next = root->right; // making left child's next point to right child
    if (root->next)
        root->right->next = root->next->left; // right child's next point to its parent's next's left node
    root->left = connect(root->left);         // connect all next pointers in left subtree
    root->right = connect(root->right);       // connect all next pointers in right subtree
    return root;
}