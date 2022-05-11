#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int getRoomTeleport(map<int, int> &m, vector<int> &ns)
{
    while (ns.size() > 0)
    {
        int key = ns[ns.size() - 1];
        if (m.find(key) == m.end())
        {
            int output = ns[ns.size() - 1];
            ns.pop_back();
            return output;
        }
        ns.pop_back();
    }
    return 0;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        int r, p;
        cin >> r >> p;
        if (K >= N)
        {
            long long sum = 0;
            for (int i = 0; i < N; i++)
            {
                cout << "T " << i + 1 << endl;
                int x;
                cin >> r >> x;
                if (x == -1)
                {
                    return 0;
                }
                sum += x;
            }
            cout << "E " << (sum / 2) << endl;
        }
        else
        {
            long long sum = 0;
            map<int, int> M;
            vector<int> ns;
            for (int i = 0; i < N; i++)
            {
                ns.push_back(i + 1);
            }
            for (int i = 0; i < K / 2; i++)
            {
                int node = getRoomTeleport(M, ns);
                cout << "T " << node << endl;
                int x;
                cin >> r >> x;
                if (x == -1)
                {
                    return 0;
                }
                sum += x;
                M[r] = x;
                cout << "W " << endl;
                cin >> r >> x;
                M[r] = x;
            }
            double est_deg = (double)sum / (K / 2);
            double ans = 0;
            for (int i = 1; i <= N; i++)
            {
                if (M.find(i) == M.end())
                    ans += est_deg;
                else
                {
                    ans += M[i];
                }
            }
            cout << "E " << ((long long)(ans / 2 + 0.5)) << endl;
        }
    }
}