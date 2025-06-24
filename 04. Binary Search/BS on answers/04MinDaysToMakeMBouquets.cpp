#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k)
{
    int cnt = 0;
    int noOfBouq = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
            cnt++;
        else
        {
            noOfBouq += (cnt / k);
            cnt = 0;
        }
    }
    noOfBouq += (cnt / k);
    return (noOfBouq >= m);
}

int minDays(vector<int> bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long totalFlowers = m * 1LL * k * 1LL;
    if (totalFlowers > n)
        return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(bloomDay, mid, m, k))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}