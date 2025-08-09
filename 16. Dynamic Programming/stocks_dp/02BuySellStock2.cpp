#include <bits/stdc++.h>
using namespace std;

int func(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == prices.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy)
        profit = max((-prices[i] + func(i + 1, false, prices, dp)),
                     (func(i + 1, true, prices, dp)));
    else
        profit = max((prices[i] + func(i + 1, true, prices, dp)),
                     (func(i + 1, false, prices, dp)));

    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return func(0, true, prices, dp);
}
int func(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == prices.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];
    int profit = 0;
    if (buy)
    {
        profit = max((-prices[i] + func(i + 1, false, prices, dp)),
                     (func(i + 1, true, prices, dp)));
    }
    else
    {
        profit = max((prices[i] + func(i + 1, true, prices, dp)),
                     (func(i + 1, false, prices, dp)));
    }
    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    // Recursion + Memoization
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return func(0, true, prices, dp);

    // Tabulation
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][1] = 0;
    dp[n][0] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            else
                profit = max((prices[i] + dp[i + 1][1]), dp[i + 1][0]);
            dp[i][buy] = profit;
        }
    }

    return dp[0][1];

    // Space Optimization
    int n = prices.size();
    vector<int> dp1(2, 0);

    dp1[1] = 0;
    dp1[0] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[i] + dp1[0], dp1[1]);
            else
                profit = max((prices[i] + dp1[1]), dp1[0]);
            dp1[buy] = profit;
        }
    }

    return dp1[1];
}