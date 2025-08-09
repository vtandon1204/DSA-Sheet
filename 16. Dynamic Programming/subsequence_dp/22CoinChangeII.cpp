#include <bits/stdc++.h>
using namespace std;

int func(int ind, int amt, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
        return (amt % arr[0] == 0) ? 1 : 0;

    if (dp[ind][amt] != -1)
        return dp[ind][amt];

    int notpick = func(ind - 1, amt, arr, dp);
    int pick = 0;
    if (arr[ind] <= amt)
        pick = func(ind, amt - arr[ind], arr, dp);

    return dp[ind][amt] = notpick + pick;
}
int change(int amount, vector<int> &coins)
{
    // Recursion + Memoization
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return func(n - 1, amount, coins, dp);

    // Tabulation
    int n = coins.size();
    vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

    for (int amt = 0; amt <= amount; amt++)
    {
        if (amt % coins[0] == 0)
            dp[0][amt] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int amt = 0; amt <= amount; amt++)
        {
            long long notpick = dp[ind - 1][amt];
            long long pick = 0;
            if (coins[ind] <= amt)
                pick = dp[ind][amt - coins[ind]];

            dp[ind][amt] = notpick + pick;
        }
    }

    return (int)(dp[n - 1][amount]);

    // Space Optimization
    int n = coins.size();
    vector<long long> prev(amount + 1, 0);

    for (int amt = 0; amt <= amount; amt++)
    {
        if (amt % coins[0] == 0)
            prev[amt] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<long long> curr(amount + 1, 0);
        for (int amt = 0; amt <= amount; amt++)
        {
            long long notpick = prev[amt];
            long long pick = (coins[ind] <= amt) ? curr[amt - coins[ind]] : 0;
            curr[amt] = notpick + pick;
        }
        prev = curr;
    }

    return (int)(prev[amount]);
}