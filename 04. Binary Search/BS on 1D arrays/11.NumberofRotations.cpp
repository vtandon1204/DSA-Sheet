#include <bits/stdc++.h>
using namespace std;

int cntRotations(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mini = INT_MAX;
    int ind = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            if (arr[low] < mini)
            {
                mini = arr[low];
                ind = low;
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < mini)
            {
                mini = arr[low];
                ind = low;
            }
            low = mid+1;
        }
        else
        {
            if (arr[mid] < mini)
            {
                mini = arr[mid];
                ind = mid;
            }
            high = mid-1;
        }
    }
    return ind;
}