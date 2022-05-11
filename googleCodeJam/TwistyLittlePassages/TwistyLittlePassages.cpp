#include <bits/stdc++.h>
using namespace std;
long long getRoomTeleport(unordered_map<long long, long long> &m, vector<long long> &ns)
{
    while (ns.size() > 0)
    {
        long long key = ns[ns.size() - 1];
        if (m.find(key) == m.end())
        {
            long long output = ns[ns.size() - 1];
            ns.pop_back();
            return output;
        }
        ns.pop_back();
    }
    return 0;
}
long long getRoomTeleportWalk(unordered_map<long long, long long> &w, vector<long long> &ns)
{
    while (ns.size() > 0)
    {
        long long key = ns[ns.size() - 1];
        if (w.find(key) == w.end())
        {
            long long output = ns[ns.size() - 1];
            ns.pop_back();
            return output;
        }
        ns.pop_back();
    }
    return 0;
}
long long estimate(unordered_map<long long, long long> &m, long long n, long long k, long long sum, long long tCount)
{
    double des = sum / tCount;
    long long total = 0;
    for (long long i = 1; i <= n; i++)
    {
        if (m.find(i) != m.end())
        {
            total += m[i];
        }
        else
        {
            total += des;
        }
    }
    return total / 2 + 0.5;
}
int main()
{
    long long t;
    cin >> t;
    long long count = 1;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        unordered_map<string, long long> passage;
        unordered_map<long long, long long> m;
        unordered_map<long long, long long> w;
        long long r, p;
        long long i = 0;
        long long roomThatWalk = 0;
        long long totalVisited = 0;
        vector<long long> ns;
        vector<long long> ws;
        for (long long i = 0; i < n; i++)
        {
            ns.push_back(i + 1);
            ws.push_back(i + 1);
        }
        long long roomNo = -1;
        long long sumP = 0;
        long long tCount = 0;

        while (i < k)
        {
            cin >> r >> p;
            if (roomThatWalk == 0)
            {
                sumP += p;
            }
            if (m.find(r) == m.end())
            {
                m[r] = p;
            }
            if (w.find(r) == w.end())
            {
                w[r]++;
                cout << "W" << endl;
                roomThatWalk = r;
            }
            else if (roomNo != 0)
            {
                roomNo = getRoomTeleport(m, ns);
                cout << "T " << roomNo << endl;
                tCount++;
                roomThatWalk = 0;
            }
            else
            {
                long long walk = getRoomTeleportWalk(m, ws);
                if (walk == 0)
                {
                    break;
                }
                cout << "T " << walk << endl;
                roomThatWalk = 0;
            }
            i++;
        }
        cin >> r >> p;
        if (m.find(r) == m.end())
        {
            m[r] = p;
        }
        long long total = estimate(m, n, k, sumP, tCount);
        cout << "E " << total << endl;
    }
}