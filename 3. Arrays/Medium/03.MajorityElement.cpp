#include <bits/stdc++.h>
int majorityElement(vector<int> &v)
{
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > (v.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}