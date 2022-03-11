#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m + n > 0)
    {
        int l = m - 1;
        int r = n - 1;
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            if (l < 0)
            {
                nums1[i] = nums2[r--];
            }
            else if (r < 0)
            {
                nums1[i] = nums1[l--];
            }
            else
            {
                nums1[i] = nums2[r] > nums1[l] ? nums2[r--] : nums1[l--];
            }
        }
    }
}
int main()
{
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};
    merge(num1, 3, num2, 3);
    for (int i = 0; i < num1.size(); i++)
    {
        cout << num1[i] << " ";
    }
    cout << endl;
}