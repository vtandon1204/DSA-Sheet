#include <bits/stdc++.h>
using namespace std;

int func(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
        return (wt[0] <= W) ? val[0] : 0;

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notpick = func(ind - 1, W, val, wt, dp);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + func(ind - 1, W - wt[ind], val, wt, dp);

    return dp[ind][W] = max(pick, notpick);
}
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    // Recursion + Memoization
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return func(n - 1, W, val, wt, dp);

    // Tabulation
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++)
        dp[0][i] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = INT_MIN;
            if (wt[i] <= j)
                pick = val[i] + dp[i - 1][j - wt[i]];
            dp[i][j] = max(pick, notpick);
        }
    }

    return dp[n - 1][W];

    // Space Optimization

    int n = wt.size();
    vector<int> dp1(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
    {
        dp1[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = W; j >= 0; j--)
        {
            int notpick = dp1[j];
            int pick = INT_MIN;
            if (wt[i] <= j)
                pick = val[i] + dp1[j - wt[i]];
            dp1[j] = max(pick, notpick);
        }
    }

    return dp1[W];
}