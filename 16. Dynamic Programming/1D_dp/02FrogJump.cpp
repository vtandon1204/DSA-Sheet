#include <bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    // recursion
    if (n = 0)
        return 0;

    int energy1 = 0; // 
    int energy2 = INT_MAX;

    energy1 = frogJump(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    energy2 = frogJump(n - 2, heights) + abs(heights[n] - heights[n - 2]);

    return min(energy1, energy2);

    // memoization
    if (n = 0)
        return 0;

    vector<int> dp(n + 1, -1);

    if (dp[n] != -1)
        return dp[n];

    int energy1 = 0;
    int energy2 = INT_MAX;

    energy1 = dp[n - 1] + abs(heights[n] - heights[n - 1]);
    energy2 = dp[n - 2] + abs(heights[n] - heights[n - 2]);

    return dp[n] = min(energy1, energy2);

    // tabulation
    if (n = 0)
        return 0;
    vector<int> dp(n + 1, 0);
    int energy1 = 0;
    int energy2 = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        energy1 = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        energy2 = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(energy1, energy2);
    }
    return dp[n];

    // space optimization
    if (n == 0)
        return 0;

    int energy1 = 0;
    int energy2 = INT_MAX;
    int a = 0; 
    int b = 0;
    int ans;
    for (int i = 1; i <= n; i++)
    {
        energy1 = b + abs(heights[i] - heights[i - 1]);
        if (i > 1)
            energy2 = a + abs(heights[i] - heights[i - 2]);
        ans = min(energy1, energy2);
        a = b;
        b = ans;
    }
    return ans;
}