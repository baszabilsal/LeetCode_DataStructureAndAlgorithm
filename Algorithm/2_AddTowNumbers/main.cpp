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
void solve(ListNode *output, ListNode *l1, ListNode *l2, int addVal)
{
    if (l1 || l2 || addVal > 0)
    {
        if (!l2)
        {
            l2 = new ListNode();
        }
        if (!l1)
        {
            l1 = new ListNode();
        }
        int val = addVal + l1->val + l2->val;
        int realVal = val % 10;
        int addNextVal = val / 10;
        output->next = new ListNode(realVal);
        solve(output->next, l1->next, l2->next, addNextVal);
    }
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *output = new ListNode();
    0->7 solve(output, l1, l2, 0);
    return output->next;
}
int main()
{
    cout << (6 ^ 3 ^ 5 ^ 3 ^ 6) << endl;
}