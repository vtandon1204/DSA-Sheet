#include <bits/stdc++.h>
using namespace std;

int frogJumpKDistance(int n, vector<int> &heights, int k)
{
    // recursion
    if (n == 0)
        return 0;
    int min_energy = INT_MAX;
    int energy;
    for (int i = 1; i <= k; i++)
    {
        if (n >= i)
            energy = frogJumpKDistance(n - i, heights, k) + abs(heights[n] - heights[n - i]);
        min_energy = min(min_energy, energy);
    }
    return min_energy;

    // memoization
    if (n == 0)
        return 0;
    int min_energy = INT_MAX;
    int n = heights.size();
    int energy;
    vector<int> dp(n + 1, -1);
    if (dp[n] != -1)
        return dp[n];
    for (int i = 1; i <= k; i++)
    {
        if (n >= i)
            energy = frogJumpKDistance(n - i, heights, k) + abs(heights[n] - heights[n - i]);
        min_energy = min(min_energy, energy);
    }
    return dp[n] = min_energy;

    // tabulation
    if (n == 0)
        return 0;
    int min_energy = INT_MAX;
    int n = heights.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    int energy;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (j >= i)
                energy = dp[j - i] + abs(heights[j] - heights[j - i]);
            min_energy = min(min_energy, energy);
        }
        dp[j] = min_energy;
    }
    return dp[n];

}