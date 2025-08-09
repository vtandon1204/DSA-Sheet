#include <bits/stdc++.h>
using namespace std;

int cntPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] =
               cntPaths(i - 1, j, m, n, dp) + cntPaths(i, j - 1, m, n, dp);
}
int uniquePaths(int m, int n)
{
    // Recursion + Memoization
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return cntPaths(m - 1, n - 1, m, n, dp);

    // **************************************************************
    // Tabulation
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Base Case: start position
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];

    // **************************************************************
    // Space Optimization
    int N = m + n - 2;
    int R = n - 1;
    double res = 1;
    for (int i = 1; i <= R; i++)
    {
        res = res * (N - R + i) / i;
    }
    return (int)res;
}