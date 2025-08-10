#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &vis)
{
    vis[x][y] = true;

    for (auto &dir : dirs)
    {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
            board[nx][ny] == 'O' && !vis[nx][ny])
        {
            dfs(nx, ny, board, vis);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    rows = board.size();
    cols = board[0].size();

    vector<vector<bool>> vis(rows, vector<bool>(cols, false));

    // Step 1: Mark 'O's connected to borders
    for (int i = 0; i < rows; i++)
    {
        if (board[i][0] == 'O' && !vis[i][0])
            dfs(i, 0, board, vis);
        if (board[i][cols - 1] == 'O' && !vis[i][cols - 1])
            dfs(i, cols - 1, board, vis);
    }
    for (int j = 0; j < cols; j++)
    {
        if (board[0][j] == 'O' && !vis[0][j])
            dfs(0, j, board, vis);
        if (board[rows - 1][j] == 'O' && !vis[rows - 1][j])
            dfs(rows - 1, j, board, vis);
    }

    // Step 2: Flip all unvisited 'O's to 'X'
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
        }
    }
}