#include <bits/stdc++.h>
int findFloor_upperBound(vector<long long> v, long long n, long long x)
{

    // Your code here
    int start = 0;
    int end = n - 1;
    int floor = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] <= x)
        {
            floor = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return floor;
}