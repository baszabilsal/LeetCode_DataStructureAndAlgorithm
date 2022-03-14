#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> m;
        vector<int> output;
        for (int i = 0; i < nums1.size(); i++)
        {
            m[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (m[nums2[i]] > 0)
            {
                m[nums2[i]]--;
                output.push_back(nums2[i]);
            }
        }
        return output;
    }
};
int main()
{
    vector<int> nums1 = {1, 2, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution st;
    vector<int> output = st.intersect(nums1, nums2);
    for (int i = 0; i < output.size(); ++i)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}