#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] <= k)
    //         k++; // shifting k
    //     else
    //         break;
    // }
    // return k;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // return high + 1 + k;
    return low + k;
}