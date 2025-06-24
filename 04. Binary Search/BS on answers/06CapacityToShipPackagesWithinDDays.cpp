#include <bits/stdc++.h>
using namespace std;

bool func(vector<int> &arr, int days, int mid)
{
    int n = arr.size();
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] <= mid)
            sum += arr[i];
        else
        {
            cnt++;
            sum = arr[i];
        }
        if (cnt > days)
            return false;
    }
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (func(weights, days, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}