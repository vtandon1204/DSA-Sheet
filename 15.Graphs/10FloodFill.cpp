#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void func(vector<vector<int>> &image, int sr, int sc, int color, int cell)
{
    int row = image.size();
    int col = image[0].size();
    image[sr][sc] = color;
    for (auto d : dir)
    {
        int nrow = sr + d[0];
        int ncol = sc + d[1];
        if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && image[nrow][ncol] == cell)
            func(image, nrow, ncol, color, cell);
    }
    return;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int cell = image[sr][sc];
    if (cell != color)
        func(image, sr, sc, color, cell);
    return image;
}