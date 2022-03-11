

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
        vector<int> nums;
        map<int, int> m;
        while (head)
        {
            if (m[head->val] == 0)
            {
                nums.push_back(head->val);
            }
            m[head->val]++;
            head = head->next;
        }
        head = new ListNode();
        ListNode *temp = head;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] == 1)
            {
                temp->next = new ListNode(nums[i]);
                temp = temp->next;
            }
        }
        return head->next;
    }
};

int main()
{
}