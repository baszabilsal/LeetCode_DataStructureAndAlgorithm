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

class Solution
{
public:
    int solve(ListNode *head, int val)
    {
        if (head)
        {
            int returnVal = solve(head->next, val);
            if (returnVal == val)
            {
                head->next = head->next->next;
            }
            return head->val;
        }
        else
        {
            return -1;
        }
    }
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *output = new ListNode();
        output->next = head;
        solve(output, val);
        return output->next;
    }
};

int main()
{
}