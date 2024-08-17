#include <bits/stdc++.h>
int setBit(int n)
{
    // Write Your Code here
    int ans = n | (n + 1);
    return ans;
}