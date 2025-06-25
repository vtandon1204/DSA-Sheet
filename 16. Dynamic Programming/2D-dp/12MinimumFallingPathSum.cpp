#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &matrix, int n, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
        return 1e9;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + func(matrix, n, i - 1, j, dp);
    int leftDiag = matrix[i][j] + func(matrix, n, i - 1, j - 1, dp);
    int rightDiag = matrix[i][j] + func(matrix, n, i - 1, j + 1, dp);

    return dp[i][j] = min(up, min(leftDiag, rightDiag));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    // Recursion + Memoization
    int n = matrix.size();
    int ans = INT_MAX;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int j=0;j<n;j++){
        ans = min(ans,func(matrix,n,n-1,j,dp));
    }
    return ans;

    // Tabulation
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = dp[i - 1][j];
            int leftDiag = (j > 0) ? dp[i - 1][j - 1] : 1e9;
            int rightDiag = (j < n - 1) ? dp[i - 1][j + 1] : 1e9;

            dp[i][j] = matrix[i][j] + min(up, min(leftDiag, rightDiag));
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}