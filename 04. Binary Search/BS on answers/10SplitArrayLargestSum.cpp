#include <bits/stdc++.h>
using namespace std;

int cntSplits(vector<int> &arr, int mid)
{
    long long sum = 0;
    int cnt = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            cnt++;
            sum = arr[i];
        }
    }
    return cnt;
}
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
        return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (cntSplits(nums, mid) > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}