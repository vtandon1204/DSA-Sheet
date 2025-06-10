#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    // recursion
    if (n <= 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2); // add the number of ways to reach the previous two steps

    // memoisation
    vector<int> dp(n + 1, -1); // dp array to store results
    if (n <= 1)
        return 1;
    if (dp[n] != -1) // check if already computed
        return dp[n];
    return dp[n] = climbStairs(n - 1) + climbStairs(n - 2); // store the result in dp[n] before returning

    // tabulation
    vector<int> dp(n + 1, 0);
    if (n <= 1)
        return 1;
    dp[0] = 1; // base case: 1 way to stay on the ground (0th step)
    dp[1] = 1; // base case: 1 way to reach the first step
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // fill the dp array iteratively
    }
    return dp[n]; // return the value for n steps

    // space optimisation
    if (n <= 1)
        return 1;
    int a = 1; 
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
        int ans = a + b; 
        a = b;
        b = ans;
    }
    return b;
}