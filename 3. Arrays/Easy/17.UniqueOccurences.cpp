#include <bits/stdc++.h>
bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    set<int> s;
    for (auto it : mp)
    {
        s.insert(it.second);
    }
    return mp.size() == s.size();
}