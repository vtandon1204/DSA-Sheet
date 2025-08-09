#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    // Push all 0s into queue and set distance 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        int x = front.first;
        int y = front.second;
        q.pop();

        for (auto dir : directions)
        {
            int dx = dir.first;
            int dy = dir.second;
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (ans[nx][ny] > ans[x][y] + 1)
                {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return ans;
}