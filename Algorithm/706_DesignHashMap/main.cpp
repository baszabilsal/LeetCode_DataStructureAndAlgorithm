#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
public:
    const static int N = 1000000;
    int map[N] = {-1};
    MyHashMap()
    {
        for (int i = 0; i < N; i++)
        {
            map[i] = -1;
        }
    }

    void put(int key, int value)
    {
        map[key] = value;
    }

    int get(int key)
    {
        return map[key];
    }

    void remove(int key)
    {
        map[key] = -1;
    }
};

int main()
{
}