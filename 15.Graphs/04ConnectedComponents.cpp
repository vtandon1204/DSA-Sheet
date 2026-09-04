#include <bits/stdc++.h>
using namespace std;
void traversal(int node)
{
}
int main()
{
    int n;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            traversal(i);
    }
}