#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, string word1, string word2, vector<vector<int>> &dp)
{
    // base case
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (word1[i] == word2[j])
        return func(i - 1, j - 1, word1, word2, dp); // matching

    // not matching
    int insertChar = 1 + func(i, j - 1, word1, word2, dp);
    int deleteChar = 1 + func(i - 1, j, word1, word2, dp);
    int replaceChar = 1 + func(i - 1, j - 1, word1, word2, dp);

    return dp[i][j] = min({insertChar, deleteChar, replaceChar});
}
int minDistance(string word1, string word2)
{
    // Recursion + Memoization
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return func(n - 1, m - 1, word1, word2, dp);

    // Tabulation
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // matching
            else
            {
                int insertChar = 1 + dp[i][j - 1];
                int deleteChar = 1 + dp[i - 1][j];
                int replaceChar = 1 + dp[i - 1][j - 1];

                dp[i][j] = min({insertChar, deleteChar, replaceChar});
            }
        }
    }

    return dp[n][m];
}