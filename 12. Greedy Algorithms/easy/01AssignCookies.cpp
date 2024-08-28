#include <bits/stdc++.h>
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int s_index = 0;
    int g_index = 0;
    while (s_index < s.size() && g_index < g.size())
    {
        if (g[g_index] <= s[s_index])
        {
            g_index++;
        }
        s_index++;
    }
    return g_index;
}