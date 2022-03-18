#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> front;
    stack<int> back;
    MyQueue()
    {
    }

    void push(int x)
    {
        back.push(x);
    }

    int pop()
    {
        int peak = peek();
        front.pop();
        return peak;
    }

    int peek()
    {
        if (front.size() == 0)
        {
            while (back.size() > 0)
            {
                front.push(back.top());
                back.pop();
            }
        }
        return front.top();
    }

    bool empty()
    {
        return back.size() == 0 && front.size() == 0;
    }
};
int main()
{
    Solution st;
    vector<vector<char>> nums = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'D', 'D', 'E', 'E'}};
    string s = "SEE";
    cout << st.exist(nums, s) << endl;
}