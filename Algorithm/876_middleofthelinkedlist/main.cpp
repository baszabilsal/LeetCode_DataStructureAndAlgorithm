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
ListNode *middleNode(ListNode *head)
{
    auto slow = head;
    auto fast = head->next;
    while (fast)
    {
        slow = slow->next;
        if (!fast->next)
            break;
        fast = fast->next->next;
    }
    return slow;
}
void printList(ListNode *head)
{
    cout << head->next->val << " ";
}
int main()
{

    ListNode a[5] = {1, 2, 3, 4, 5};
    printList(a);
    auto b = middleNode(a);
    while (b)
    {
        printList(b);
        b = b->next;
    }
    cout << endl;
    return 0;
}