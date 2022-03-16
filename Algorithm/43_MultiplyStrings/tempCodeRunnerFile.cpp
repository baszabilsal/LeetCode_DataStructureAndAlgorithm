#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string output;
    int _deci = 0;

    string getSumDefault(int total)
    {
        string sum = "";
        for (int i = 0; i < total; i++)
        {
            sum += '0';
        }
        return sum;
    }
    string multiply(string num1, string num2)
    {
        vector<string> numMulti;
        int deci = 0;
        int maxSize = 0;
        string output = "";
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            string sum = getSumDefault(((num2.size() - 1) - i));
            for (int j = num1.size() - 1; j >= 0; j--)
            {

                int total = ((num1[j] - '0') * (num2[i] - '0'));
                total += deci;
                deci = total / 10;
                sum += to_string(total % 10);
            }
            if (deci > 0)
            {
                sum = to_string(deci) + sum;
            }
            maxSize = max(maxSize, sum.size());
            numMulti.push_back(sum);
        }
        return output;
    }
};
int main()
{
    Solution st;
    string s = "12";
    string p = "13";
    cout << st.multiply(s, p) << endl;
}