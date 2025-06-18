#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &mat)
{
    // Brute force
    vector<int> arr;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            arr.push_back(mat[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    int mid = arr.size() / 2;
    return arr[mid];
}

// Optimal
int func(vector<int> &arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
int cntSmallEqual(vector<vector<int>> &mat, int m, int n, int mid)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += func(mat[i], n, mid);
    }
    return cnt;
}
int median(vector<vector<int>> &mat)
{
    int low = INT_MAX;
    int high = INT_MIN;
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][n - 1]);
    }
    int req = (m * n) / 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int smallEqual = cntSmallEqual(mat, m, n, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}