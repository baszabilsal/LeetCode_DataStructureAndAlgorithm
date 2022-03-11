#include <bits/stdc++.h>
#include <string>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    if (n == 0)
    {
        return n;
    }
    uint32_t output = 0;
    string number = "";
    int t = 32;
    while (t--)
    {
        bool bit = ((n & 1) == 1) ? 1 : 0;
        number += bit ? "1" : "0";
        output = (output << 1) | bit;
        n = n >> 1;
    }
    return output;
}
int main()
{
    uint32_t n = 0b00000010100101000001111010011100;
    cout << reverseBits(n) << endl;
}