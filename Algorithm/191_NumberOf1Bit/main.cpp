#include <bits/stdc++.h>
using namespace std;
int hammingWeight(uint32_t n)
{
    if (n == 0)
        return 0;
    int numberOfOnes = 0;

    while (n != 0)
    {
        cout << n << endl;
        if ((n & 1) == 1)
        {
            numberOfOnes++;
        }
        n = n >> 1;
    }
    return numberOfOnes;
}
int main()
{
    uint32_t n = 00000000000000000000000000001011;
    cout << hammingWeight(n) << endl;
}