#include <bits/stdc++.h>
vector<int> MinimumCoins(int n)
{
    vector<int> den = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    for (int i = den.size() - 1; i >= 0; i--)
    {
        while (n >= den[i])
        {
            n -= den[i];
            ans.push_back(den[i]);
        }
    }
    return ans;
}