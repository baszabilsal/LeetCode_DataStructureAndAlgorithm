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
    void mergeTwoRecursive(ListNode *node, ListNode *list1, ListNode *list2)
    {
        if (list1 || list2)
        {
            if (list1 && list2)
            {
                if (list2->val < list1->val)
                {
                    node->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                else
                {
                    node->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
            }
            else if (list2)
            {
                node->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            else
            {
                node->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            mergeTwoRecursive(node->next, list1, list2);
        }
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *node = new ListNode();
        mergeTwoRecursive(node, list1, list2);
        return node->next;
    }
};

int main()
{
}