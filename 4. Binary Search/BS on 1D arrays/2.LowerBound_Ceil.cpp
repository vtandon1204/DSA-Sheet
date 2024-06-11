#include <bits/stdc++.h>
int findCeil_lowerBound(vector<long long> v, long long n, long long x)
{

    // Your code here
    int start = 0;
    int end = n - 1;
    int ceil = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] >= x)
        {
            ceil = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ceil;
}