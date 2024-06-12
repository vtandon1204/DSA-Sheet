#include <bits/stdc++.h>
int maxElement(vector<vector<int>> &mat, int m, int n, int mid)
{
    int maxRow = -1;
    int max = 0;
    for (int i = 0; i < m; i++)
    {
        if (mat[i][mid] > max)
        {
            max = mat[i][mid];
            maxRow = i;
        }
    }
    return maxRow;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    // vector<int> ans(2, -1);
    int m = mat.size();
    int n = mat[0].size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int maxRow = maxElement(mat, m, n, mid);
        int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
        int right = mid + 1 < n ? mat[maxRow][mid + 1] : -1;
        if (mat[maxRow][mid] > left && mat[maxRow][mid] > right)
        {
            return {maxRow, mid};
        }
        else if (mat[maxRow][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}