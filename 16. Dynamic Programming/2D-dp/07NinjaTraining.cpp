#include <bits/stdc++.h>
using namespace std;

int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            int pts = points[day][i] + func(day - 1, i, points, dp);
            maxi = max(maxi, pts);
        }
    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Tabulation
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int i = 0; i <= 2; i++)
            {
                if (i != last)
                {
                    int pts = points[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], pts);
                }
            }
        }
    }
    return dp[n - 1][3];

    // Memoization
    // vector<vector<int>> dp(n+1,vector<int>(4,-1));
    // return func(n-1,3,points,dp);
}