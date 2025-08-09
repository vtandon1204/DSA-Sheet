#include <bits/stdc++.h>
using namespace std;

bool func(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notpick = func(arr, ind - 1, target, dp);
    bool pick = false;
    if (target >= arr[ind])
        pick = func(arr, ind - 1, target - arr[ind], dp);

    return dp[ind][target] = notpick || pick;
}
bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return func(arr, n - 1, sum, dp);
}