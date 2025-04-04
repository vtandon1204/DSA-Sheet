#include <bits/stdc++.h>
using namespace std;

// Check if there exists a subset with a given sum k in an array
bool func(int i, int sum, int n, int k, vector<int> &a)
{
    if (i == n)
    {
        return sum == k ? true : false;
    }

    if (func(i + 1, sum + a[i], n, k, a) == true)
        return true;
    if (func(i + 1, sum, n, k, a) == true)
        return true;
    return false;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return func(0, 0, n, k, a);
}