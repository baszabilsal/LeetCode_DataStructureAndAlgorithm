#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> output;
    vector<char> getVectorString(char d)
    {
        vector<char> output;
        switch (d)
        {
        case '2':
            output = {'a', 'b', 'c'};
            break;
        case '3':
            output = {'d', 'e', 'f'};
            break;
        case '4':
            output = {'g', 'h', 'i'};
            break;
        case '5':
            output = {'j', 'k', 'l'};
            break;
        case '6':
            output = {'m', 'n', 'o'};
            break;
        case '7':
            output = {'p', 'q', 'r', 's'};
            break;
        case '8':
            output = {'t', 'u', 'v'};
            break;
        case '9':
            output = {'w', 'x', 'y', 'z'};
            break;
        }
        return output;
    }
    void solve(string digits, string temp, int start)
    {
        if (temp.size() == digits.size())
        {
            output.push_back(temp);
            return;
        }
        for (int i = start; i < digits.size(); i++)
        {
            vector<char> charList = getVectorString(digits[start]);
            for (int j = 0; j < charList.size(); j++)
            {
                solve(digits, temp + charList[j], i + 1);
            }
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return output;
        }
        string temp = "";
        solve(digits, temp, 0);
        return output;
    }
};
int main()
{
    Solution st;
    string s = "24";
    vector<string> output = st.letterCombinations(s);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}