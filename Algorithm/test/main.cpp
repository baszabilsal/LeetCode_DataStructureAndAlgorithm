#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &A)
{
    map<int, vector<pair<int, int>>> m;
    int maxSumDuplicated = 1;
    int i = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        int sum = A[i] + A[i + 1];
        if (m.find(sum) != m.end())
        {
            vector<pair<int, int>> position = m[sum];
            bool isDuplicated = false;
            for (int j = 0; j < position.size(); j++)
            {
                if (position[j].first == i ||
                    position[j].first == i + 1 ||
                    position[j].second == i ||
                    position[j].second == i + 1)
                {
                    isDuplicated = true;
                    break;
                }
            }
            if (!isDuplicated)
            {
                m[sum].push_back({i, i + 1});
            }
        }
        else
        {
            m[sum].push_back({i, i + 1});
        }
    }
    for (auto const &imap : m)
    {
        int size = m[imap.first].size();
        maxSumDuplicated = max(size, maxSumDuplicated);
    }
    return maxSumDuplicated;
}
int main()
{
    vector<int> st = {3, 1, 3, 2, 2, 3, 1, 0, 0};

    cout << solution(st) << endl;
}