#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        while (i < nums.size() && nums[i] == val)
        {
            i++;
        }
        if (i < nums.size())
        {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}
int main()
{
    vector<int> output = {3, 2, 2, 3};
    cout << removeElement(output, 3) << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}