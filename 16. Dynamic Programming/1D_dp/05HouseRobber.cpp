#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &arr)
{
    // recursion
    if (n == 0)
        return arr[0];

    int pick = INT_MIN;
    int notpick = 0;
    if (n > 1)
        pick = arr[n] + func(n - 2, arr);
    notpick = func(n - 1, arr);

    return max(pick, notpick);

    // memoization
    if (n == 0)
        return arr[0];

    int pick = INT_MIN;
    int notpick = 0;
    vector<int> dp(n + 1, -1);
    if (dp[n] != -1)
        return dp[n];
    if (n > 1)
        pick = arr[n] + func(n - 2, arr);
    notpick = func(n - 1, arr);

    return dp[n] = max(pick, notpick);

    // tabulation
    if (n == 0)
        return arr[n];

    int pick;
    int notpick;
    vector<int> dp(n + 1, 0);
    dp[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            pick = arr[i] + dp[i - 2];
        else
            pick = arr[i];
        notpick = dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[n];

    // space optimization
    if (n == 0)
        return arr[0];

    int pick = INT_MIN;
    int notpick = 0;
    int a = 0;
    int b = arr[0];
    int ans;
    for (int i = 1; i < n; i++)
    {
        if (i > 1)
            pick = arr[i] + a;
        notpick = b;
        ans = max(pick, notpick);
        a = b;
        b = ans;
    }
    return ans;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    return func(n, nums);
}