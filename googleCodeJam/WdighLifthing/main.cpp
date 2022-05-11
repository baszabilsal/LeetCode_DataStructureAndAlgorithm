#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int count = 1;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int ar[n][w];
        int min[w] = {MAX_INT};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> ar[i][j];
                if (min[j] > ar[i][j])
                {
                    min[j] = ar[i][j];
                }
            }
        }
        int total = 0;
        map<int, int> m;
        for (int i = 0; i < w; i++)
        {
            m[i] = min[i];
            total += min[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (m[j] < ar[i][j])
                {
                    m[j] = ar[i][j];
                    total += ar[i][j] - min[j];
                }
            }
        }
        cout << "Case #" << count << ": ";
        cout << t << endl;
        count++;
    }
}