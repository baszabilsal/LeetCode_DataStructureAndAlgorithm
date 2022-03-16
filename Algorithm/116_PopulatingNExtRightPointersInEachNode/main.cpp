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
    vector<Node *> quence;
    Node *connect(Node *root)
    {
        Node *node = nullptr;
        if (root)
        {
            node = new Node(root->val);
            if (root->left)
            {
                root->left->next = new Node(1);
                quence.push_back(root->left);
            }
            if (root->right)
            {
                quence.push_back(root->right);
            }
            bfs(node);
        }
        return node;
    }
    void bfs(Node *node)
    {
        while (quence.size() > 0)
        {
            Node *nodeQuence = quence.front();
            quence.erase(quence.begin());
            if (nodeQuence)
            {
                bool isNextRow = false;
                if (nodeQuence->next)
                {
                    isNextRow = true;
                }
                if (nodeQuence->left)
                {
                    if (isNextRow)
                    {
                        nodeQuence->left->next = new Node(1);
                    }
                    quence.push_back(nodeQuence->left);
                }
                if (nodeQuence->right)
                {
                    quence.push_back(nodeQuence->right);
                }
                if (isNextRow)
                {
                    node->right = new Node(nodeQuence->val);
                    bfs(node->right);
                }
                else
                {
                    node->next = new Node(nodeQuence->val);
                    bfs(node->next);
                }
            }
        }
    }
};
int main()
{
}