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
    int nOutput = 0;
    ListNode *solve(ListNode *head)
    {
        if (head)
        {
            head->next = solve(head->next);
            nOutput--;
            if (nOutput == 0)
            {
                return head->next;
            }
            else
            {
                return head;
            }
        }
        else
        {
            return head;
        }
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        nOutput = n;
        ListNode *output = new ListNode();
        output->next = head;
        solve(output);
        return output->next;
    }
};
int main()
{
}