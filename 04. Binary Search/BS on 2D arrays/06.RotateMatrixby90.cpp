#include <bits/stdc++.h>
void rotate(vector<vector<int>> &mat)
{
    int n = mat.size();
    // 1. Transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // 2. reverse
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}