#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string output;
    int _deci = 0;
    void sum(int maxSize, vector<string> &numMulti, int total, int i, int j)
    {
        if (i >= maxSize && _deci == 0)
        {
            return;
        }
        if (j >= numMulti.size())
        {
            total += _deci;
            output += to_string(total % 10);
            _deci = total / 10;
            sum(maxSize, numMulti, 0, i + 1, 0);
        }
        else
        {
            if (i < numMulti[j].size())
            {
                total += (numMulti[j][i] - '0');
            }
            sum(maxSize, numMulti, total, i, j + 1);
        }
    }
    string getSumDefault(int total)
    {
        string sum = "";
        for (int i = 0; i < total; i++)
        {
            sum += '0';
        }
        return sum;
    }
    void multiplySolution(string num1, string num2)
    {
        vector<string> numMulti;
        int maxSize = 0;
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            int deci = 0;
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
                sum += to_string(deci);
            }
            int s = sum.size();
            maxSize = max(maxSize, s);
            cout << sum << endl;
            numMulti.push_back(sum);
        }
        output = "";
        sum(maxSize, numMulti, 0, 0, 0);
        reverse(output.begin(), output.end());
    }
    string multiply(string num1, string num2)
    {
        if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0'))
        {
            return "0";
        }
        else if (num1.size() > num2.size())
        {
            multiplySolution(num1, num2);
        }
        else
        {
            multiplySolution(num2, num1);
        }
        return output;
    }
};
int main()
{
    Solution st;
    string s = "123";
    string p = "456";
    cout << st.multiply(s, p) << endl;
}