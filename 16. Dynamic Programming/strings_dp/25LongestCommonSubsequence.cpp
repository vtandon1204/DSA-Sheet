#include <bits/stdc++.h>
using namespace std;

int func(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (ind1 == 0 || ind2 == 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (text1[ind1 - 1] == text2[ind2 - 1])
        return 1 + func(ind1 - 1, ind2 - 1, text1, text2, dp);

    return dp[ind1][ind2] = max(func(ind1 - 1, ind2, text1, text2, dp), func(ind1, ind2 - 1, text1, text2, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    // Recursion + Memoization
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    return func(n1, n2, text1, text2, dp);

    // Tabulation
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n1][n2];

    // Space Optimization
    vector<int> prev(n2 + 1, 0);
    vector<int> curr(n2 + 1, 0);

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(curr[j - 1], prev[j]);
        }
        curr = prev;
    }
    return prev[n2];
}