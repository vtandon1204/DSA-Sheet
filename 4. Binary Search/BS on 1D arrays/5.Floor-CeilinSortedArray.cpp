#include <bits/stdc++.h>
pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    pair<int, int> myPair;
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = n - 1;
    myPair.first = -1;
    myPair.second = -1;
    int floor = -1;
    int ceil = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= x)
        {
            floor = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > x)
        {
            ceil = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (floor != -1)
        myPair.first = arr[floor];
    if (ceil != -1)
        myPair.second = arr[ceil];
    return myPair;
}
