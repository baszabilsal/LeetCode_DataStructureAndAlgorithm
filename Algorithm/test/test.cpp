#include <bits/stdc++.h>
using namespace std;
class Module
{
public:
    int value;
    vector<Module *> subModules;
};
Module *getModuleChainReaction(vector<vector<int>> &chains)
{
    unordered_map<int, Module *> m;
    sort(chains.begin(), chains.end());
    for (int i = chains.size() - 1; i >= 0; i--)
    {
        Module *subMd = m[chains[i][2] + 1];
        if (!subMd)
        {
            subMd = new Module();
        }
        subMd->value = chains[i][1];
        Module *md = m[chains[i][0]];
        if (!md)
        {
            md = new Module();
        }
        md->subModules.push_back(subMd);

        m[chains[i][0]] = md;
    }
    return m[0];
}
int solve(Module *m)
{
    if (m)
    {
        int value = m->value;
        if (m->subModules.size() > 0)
        {
            int total = 0;
            int minValue = solve(m->subModules[0]);
            int minIndex = 0;
            total += minValue;
            for (int i = 1; i < m->subModules.size(); i++)
            {
                int subValue = solve(m->subModules[i]);
                total += subValue;
                if (minValue > subValue)
                {
                    minValue = subValue;
                    minIndex = i;
                }
            }
            total -= m->subModules[minIndex]->value;
            total += max(m->subModules[minIndex]->value, value);
            return total;
        }
        else
        {
            return value;
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> a = {{0, 1, 0}, {1, 100, 1}, {2, 100, 2}, {1, 90, 3}, {2, 80, 4}, {3, 100, 5}, {1, 90, 6}, {3, 100, 7}};
    Module *m = getModuleChainReaction(a);
    cout << solve(m) << endl;
}
1 1000000 2 4 1 1 3 5 2 2 2

    int j = unpassageRooms.size();
bool isValid = true;
if (isValid)
{
    j--;
    string key = getPassageKey(unpassageRooms[i][1], unpassageRooms[j][1]);
    isValid = passage.find(key) != passage.end();
}