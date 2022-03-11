#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    vector<double> nums;
    int size = m + n;
    double sum = 0.0;
    if (size > 0)
    {
        int med = (size / 2) + 1;
        bool isOdd = size % 2 == 1;
        for (int i = 0; i < med; i++)
        {
            if (m == 0)
            {
                nums.push_back(nums2[--n]);
            }
            else if (n == 0)
            {
                nums.push_back(nums1[--m]);
            }
            else
            {
                nums.push_back(nums2[n - 1] < nums1[m - 1] ? nums1[--m] : nums2[--n]);
            }
            if (i == med - 1)
            {
                if (isOdd)
                {
                    return nums[i];
                }
                else
                {
                    return (nums[i] + nums[i - 1]) / 2;
                }
            }
        }
    }
    return 0;
}
int main()
{
    vector<int> num1 = {1, 3, 5};
    vector<int> num2 = {2, 3, 4};
    cout << findMedianSortedArrays(num1, num2) << endl;
}