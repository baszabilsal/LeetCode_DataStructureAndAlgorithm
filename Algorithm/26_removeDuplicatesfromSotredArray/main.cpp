#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[count] = nums[i];
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        {
            i++;
        }
        count++;
    }
    for (int i = count; i < nums.size(); i++)
    {
        nums.pop_back();
    }
    return count;
}
int main()
{
    vector<int> output = {1, 1, 2};
    cout << removeDuplicates(output) << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}