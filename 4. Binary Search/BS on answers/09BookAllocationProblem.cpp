#include <bits/stdc++.h>
ibool place(vector<int> &arr, int dist, int cows)
{
    int cntCows = 1;
    int last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= dist)
        {
            cntCows++;
            last = arr[i];
        }
        if (cntCows >= cows)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;
    // cout<<high<<endl;
    // for (int i = low; i <= high; i++) {
    //   if (place(stalls, i, k)) {
    //     result = i;
    //   } else {
    //     break;
    //   }
    // }
    // return result;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (place(stalls, mid, k))
        {
            // result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}