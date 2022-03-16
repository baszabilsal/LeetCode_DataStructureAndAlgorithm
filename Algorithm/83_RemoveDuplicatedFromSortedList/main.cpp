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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *output = new ListNode();
        ListNode *temp = output;
        bool isStart = true;
        while (head)
        {
            if (temp->val != head->val || isStart)
            {
                isStart = false;
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            head = head->next;
        }
        return output->next;
    }
};
int main()
{
}