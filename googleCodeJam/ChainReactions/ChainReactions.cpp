#include <bits/stdc++.h>
using namespace std;

class Module
{
public:
    long long value;
    vector<Module *> subModules;
};
Module *getModuleChainReaction(vector<vector<long long>> &chains)
{
    unordered_map<long long, Module *> m;
    sort(chains.begin(), chains.end());
    for (long long i = chains.size() - 1; i >= 0; i--)
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
long long solve(Module *m)
{
    if (m)
    {
        long long value = m->value;
        if (m->subModules.size() > 0)
        {
            long long total = solve(m->subModules[0]);
            long long minValue = m->subModules[0]->value;
            long long minIndex = 0;
            for (long i = 1; i < m->subModules.size(); i++)
            {
                long long subValue = solve(m->subModules[i]);
                total += subValue;
                if (minValue > m->subModules[i]->value)
                {
                    minValue = m->subModules[i]->value;
                    minIndex = i;
                }
            }
            if (value > m->subModules[minIndex]->value)
            {
                total -= m->subModules[minIndex]->value;
                total += value;
            }
            else
            {
                m->value = m->subModules[minIndex]->value;
            }
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
    long long t;
    cin >> t;
    long long count = 1;
    while (t--)
    {
        long long size;
        cin >> size;
        vector<vector<long long>> chains;
        for (long long i = 0; i < size; i++)
        {
            long long input;
            cin >> input;
            chains.push_back({0, input, i});
        }
        for (long long i = 0; i < size; i++)
        {
            cin >> chains[i][0];
        }
        Module *m = getModuleChainReaction(chains);
        cout << "Case #" << count << ": ";
        cout << solve(m) << endl;
        count++;
    }
}
