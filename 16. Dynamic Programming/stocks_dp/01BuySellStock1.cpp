#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int buy = prices[0];
    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        maxProfit = max(maxProfit, prices[i] - buy); // compute the max profit
        buy = min(buy, prices[i]); // keep track of minimum buying price
    }

    return maxProfit;
}