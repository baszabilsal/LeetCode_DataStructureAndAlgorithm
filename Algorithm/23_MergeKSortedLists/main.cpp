

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
    void solve(ListNode *node, vector<ListNode *> &lists)
    {
        bool isStop = true;
        int position = -1;
        int min = INT_MAX;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                isStop = false;
                if (min > lists[i]->val)
                {
                    min = lists[i]->val;
                    position = i;
                }
            }
        }
        if (!isStop)
        {

            node->next = new ListNode(lists[position]->val);
            lists[position] = lists[position]->next;
            solve(node->next, lists);
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0 || (lists.size() == 1 && lists[0] == nullptr))
        {
            return nullptr;
        }
        ListNode *node = new ListNode();
        solve(node, lists);
        return node->next;
    }
};

int main()
{
}