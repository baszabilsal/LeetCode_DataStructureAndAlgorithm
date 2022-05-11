#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    long long count = 1;
    while (t--)
    {
        int s;
        cin >> s;
        int ar[s * 2];
        int sum = 0;
        for (int i = 0; i < s; i++)
        {
            ar[i] = (i * 2) + 1;
            cout << ((i * 2) + 1) << " ";
            sum += (i * 2) + 1;
        }
        cout << endl;
        for (int i = 0; i < s; i++)
        {
            cin >> ar[s + i];
            sum += ar[s + i];
        }
        cout << sum << endl;
        sum = sum / 2;
        for (int i = 0; i < s * 2; i++)
        {
            if (sum - ar[i] >= 0)
            {
                sum -= ar[i];
                cout << ar[i] << " ";
                if (sum == 0)
                {
                    break;
                }
            }
        }
        cout << endl;
    }
}