#include <bits/stdc++.h>
using namespace std;

int func(int ind, int amt, vector<int> &coins, vector<vector<int>> dp)
{
    if (ind == 0)
        return (amt % coins[0] == 0) ? amt / coins[0] : 1e9;

    if (dp[ind][amt] != -1)
        return dp[ind][amt];

    int notpick = func(ind - 1, amt, coins, dp);
    int pick = 1e9;
    if (coins[ind] <= amt)
        pick = 1 + func(ind, amt - coins[ind], coins, dp);

    return dp[ind][amt] = min(notpick, pick);
}
int coinChange(vector<int> &coins, int amount)
{
    // Recursion + Memoization
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int res = func(n - 1, amount, coins, dp);
    return (res >= 1e9) ? -1 : res;

    // Tabulation
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

    for (int amt = 0; amt <= amount; amt++)
    {
        if (amt % coins[0] == 0)
            dp[0][amt] = amt / coins[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int amt = 0; amt <= amount; amt++)
        {
            int notpick = dp[ind - 1][amt];
            int pick = 1e9;
            if (coins[ind] <= amt)
                pick = 1 + dp[ind][amt - coins[ind]];

            dp[ind][amt] = min(notpick, pick);
        }
    }
    int res = dp[n - 1][amount];
    return (res >= 1e9) ? -1 : res;

    // Space Optimization
    int n = coins.size();
    vector<int> dp1(amount + 1, 1e9);
    for (int amt = 0; amt <= amount; amt++)
    {
        if (amt % coins[0] == 0)
            dp1[amt] = amt / coins[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int amt = 0; amt <= amount; amt++)
        {
            int notpick = dp1[amt];
            int pick = 1e9;
            if (coins[ind] <= amt)
                pick = 1 + dp1[amt - coins[ind]];
            dp1[amt] = min(notpick, pick);
        }
    }
    int res = dp1[amount];
    return (res >= 1e9) ? -1 : res;
}