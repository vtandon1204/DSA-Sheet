#include <bits/stdc++.h>
using namespace std;

int func(int ind, int buy, int maxi, vector<int> &arr,
         vector<vector<vector<int>>> &dp)
{
    if (maxi == 0)
        return 0;

    if (ind == arr.size())
        return 0;

    if (dp[ind][buy][maxi] != -1)
        return dp[ind][buy][maxi];

    int profit = 0;
    if (buy)
    {
        profit = max(-arr[ind] + func(ind + 1, 0, maxi, arr, dp),
                     func(ind + 1, 1, maxi, arr, dp));
    }
    else
    {
        profit = max(arr[ind] + func(ind + 1, 1, maxi - 1, arr, dp),
                     func(ind + 1, 0, maxi, arr, dp));
    }
    return dp[ind][buy][maxi] = profit;
}
int maxProfit(vector<int> &prices)
{
    // ***** Recursion + Memoization ******
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return func(0, 1, 2, prices, dp);

    // ***** Tabulation *****
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // maxi = 0
    for (int ind = 0; ind < n; ind++)
    {
        for (int buy = 0; buy <= 1; buy++)
            dp[ind][buy][0] = 0;
    }

    // ind = n
    for (int maxi = 0; maxi <= 2; maxi++)
    {
        for (int buy = 0; buy <= 1; buy++)
            dp[n][buy][maxi] = 0;
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int maxi = 1; maxi <= 2; maxi++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                    profit = max(-prices[ind] + dp[ind + 1][0][maxi],
                                 dp[ind + 1][1][maxi]);
                else
                    profit = max(prices[ind] + dp[ind + 1][1][maxi - 1],
                                 dp[ind + 1][0][maxi]);
                dp[ind][buy][maxi] = profit;
            }
        }
    }
    return dp[0][1][2];

    // ***** Space Optimization *****
    int n = prices.size();
    vector<vector<int>> dp1(2, vector<int>(3, 0));

    // maxi = 0
    for (int ind = 0; ind < n; ind++)
    {
        for (int buy = 0; buy <= 1; buy++)
            dp1[buy][0] = 0;
    }

    // ind = n
    for (int maxi = 0; maxi <= 2; maxi++)
    {
        for (int buy = 0; buy <= 1; buy++)
            dp1[buy][maxi] = 0;
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int maxi = 1; maxi <= 2; maxi++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                    profit = max(-prices[ind] + dp1[0][maxi],
                                 dp1[1][maxi]);
                else
                    profit = max(prices[ind] + dp1[1][maxi - 1],
                                 dp1[0][maxi]);
                dp1[buy][maxi] = profit;
            }
        }
    }
    return dp1[1][2];
}