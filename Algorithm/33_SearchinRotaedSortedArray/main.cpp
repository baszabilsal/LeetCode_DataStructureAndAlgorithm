#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();
    int output = -1;
    while (l < r)
    {
        int med = (l + r) / 2;
        r -= nums.size() == r ? 1 : 0;
        cout << med << " " << nums[med] << " " << endl;
        cout << "r : " << r << " l: " << l << " " << endl;
        if (nums[med] == target)
        {
            output = med;
            break;
        }
        else if (nums[l] == target)
        {
            output = l;
            break;
        }
        else if (nums[r] == target)
        {
            output = r;
            break;
        }
        else if (nums[med] > target)
        {
            if (target > nums[l])
            {
                if (nums[med] > nums[l])
                {
                    r = med; // med > target > l
                }
                else
                {
                    l = med + 1; // med > target > but l < med
                }
            }
            else if (target < nums[l])
            {
                if (nums[med] > nums[l])
                {
                    l = med + 1;
                }
                else
                {
                    r = med;
                }
            }
            else
            {
                output = l;
                break;
            }
        }
        else if (nums[med] < target) // nums[med] << target << nums[r]
        {
            if (target < nums[r])
            {
                if (nums[med] < nums[r])
                {
                    l = med + 1;
                }
                else
                {
                    r = med;
                }
            }
            else if (target > nums[r])
            {
                if (nums[med] < nums[r])
                {
                    r = med;
                }
                else
                {
                    l = med + 1;
                }
            }
            else
            {
                output = r;
                break;
            }
        }
    }
    return output;
}
int main()
{
    vector<int> a = {3, 1};

    cout << search(a, 3) << endl;
    return 0;
}