#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = prices[0];
        int maxPrice = 0;
        int _maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (min > prices[i])
            {
                min = prices[i];
                maxPrice = 0;
            }
            if (maxPrice < prices[i])
            {
                maxPrice = prices[i];
                _maxProfit = max(_maxProfit, maxPrice - min);
            }
        }
        return _maxProfit;
    }
};
int main()
{
    vector<int> nums1 = {7, 1, 5, 3, 6, 4};
    Solution st;
    cout << st.maxProfit(nums1) << " " << endl;

    return 0;
}