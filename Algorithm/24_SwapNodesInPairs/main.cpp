#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void solve(ListNode *node, ListNode *head)
{
    if (head)
    {
        if (head->next)
        {
            node->next = new ListNode(head->next->val, new ListNode(head->val));
            head = head->next->next;
            solve(node->next->next, head);
        }
        else
        {
            node->next = new ListNode(head->val);
            head = head->next;
        }
    }
}
ListNode *swapPairs(ListNode *head)
{
    ListNode *node = new ListNode();
    solve(node, head);
    return node->next;
}

int main()
{
}