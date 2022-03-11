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
ListNode *reverseKGroup(ListNode *head, int k)
{
    vector<int> nums;
    while (head)
    {
        nums.push_back(head->val);
        head = head->next;
    }
    ListNode *output = new ListNode();
    ListNode *temp = output;
    int t = 0;
    while (t < nums.size())
    {
        if ((t + k) - 1 < nums.size())
        {
            for (int i = (t + k) - 1; i >= t; i--)
            {
                temp->next = new ListNode(nums[i]);
                temp = temp->next;
            }
            t = t + k;
        }
        else
        {
            for (int i = t; i < nums.size(); i++)
            {
                temp->next = new ListNode(nums[i]);
                temp = temp->next;
            }
            t = nums.size();
        }
    }
    return output->next;
}

int main()
{
}