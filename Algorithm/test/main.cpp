#include <bits/stdc++.h>
using namespace ::std;

const int N = 50000 + 5;
const int LOG = 13;
const int SUM = 12 * 9 + 10;

int n;
int m;
vector<int> v;
bool vis[LOG][SUM][SUM][2][2];
long long memo[LOG][SUM][SUM][2][2];

long long DP(int pos, int prod, int suma, int menor, int start)
{
    if (suma > m)
        return 0;
    if (pos == v.size())
    {
        return prod == 0 and suma == m;
    }
    if (vis[pos][prod][suma][menor][start])
    {
        cout << suma << " " << pos << endl;
        return memo[pos][prod][suma][menor][start];
    }
    int limit = menor ? 9 : v[pos];
    long long ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        int new_prod = start ? (prod * i) % m : (i > 0 ? i % m : 0);
        int new_sum = suma + i;
        int new_start = start | (i > 0);
        ans += DP(pos + 1, new_prod, new_sum, menor | (i < v[pos]), new_start);
    }
    vis[pos][prod][suma][menor][start] = true;

    return memo[pos][prod][suma][menor][start] = ans;
}

long long f(long long x)
{
    if (x == 0)
        return 0;
    v.clear();
    while (x)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    long long ans = 0;
    for (int sum = 1; sum <= 9 * v.size(); sum++)
    {
        m = sum;
        memset(vis, 0, sizeof vis);
        ans += DP(0, 0, 0, 0, 0);
    }
    return ans;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    int caso = 1;
    while (tc--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("Case #%d: %lld\n", caso++, f(b) - f(a - 1));
    }
    return 0;
}
