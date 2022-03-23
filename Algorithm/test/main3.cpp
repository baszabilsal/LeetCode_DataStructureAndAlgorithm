#include <bits/stdc++.h>
using namespace std;
const int N = 50000 + 5;

bool DP[N][2][2][2][2][2][2];
bool S[N][2][2][2][2][2][2];
bool solve2(string &s, int start, int p1, int p2, int p3, int p4, int p5, int p6)
{
    if (p1 <= 1 && p1 == p6 && p2 == p5 && p3 == p4)
        return false;
    if (p1 <= 1 && p1 == p5 && p2 == p4)
        return false;
    if (p2 <= 1 && p2 == p6 && p3 == p5)
        return false;
    if (start >= s.size())
        return true;
    if (S[start][p1][p2][p3][p4][p5][p6])
    {
        return DP[start][p1][p2][p3][p4][p5][p6];
    }
    bool ans = 0;
    if (s[start] == '?')
    {
        ans |= solve2(s, start + 1, p2, p3, p4, p5, p6, 0);
        ans |= solve2(s, start + 1, p2, p3, p4, p5, p6, 1);
    }
    else
    {
        ans = solve2(s, start + 1, p2, p3, p4, p5, p6, s[start] - '0');
    }
    S[start][p1][p2][p3][p4][p5][p6] = true;
    return DP[start][p1][p2][p3][p4][p5][p6] = ans;
}
int main()
{
    int t;
    cin >> t;
    int count = 0;
    while (t--)
    {
        string s;
        int n;
        cin >> n >> s;
        memset(S, 0, sizeof S);
        bool isSolve = solve2(s, 0, 2, 2, 2, 2, 2, 2);
        if (isSolve)
        {
            cout << "Case #" << ++count << ": POSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << ++count << ": IMPOSSIBLE" << endl;
        }
    }
}