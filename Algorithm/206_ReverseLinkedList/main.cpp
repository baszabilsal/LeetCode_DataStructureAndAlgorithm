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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *output = nullptr;
        ListNode *temp = nullptr;
        while (head)
        {
            temp = new ListNode(head->val);
            temp->next = output;
            output = temp;
            head = head->next;
        }
        return output;
    }
};

int main()
{
}