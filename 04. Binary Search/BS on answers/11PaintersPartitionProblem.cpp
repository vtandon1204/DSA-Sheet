#include <bits/stdc++.h>
using namespace std;

int cntPainters(vector<int> &arr, int mid)
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
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    if (k > n)
        return -1;

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (cntPainters(boards, mid) > k)
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