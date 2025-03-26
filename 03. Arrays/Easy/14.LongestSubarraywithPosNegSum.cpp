#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &arr, int k)
{
    map<int, int> preSum;
    int maxlen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
            maxlen = max(i + 1, maxlen);
    }
    int rem = sum - k;
    if (preSum.find(rem) != preSum.end())
    {
        len = i - preSum.[rem];
        maxlen = max(maxlen, len);
    }
    if (preSum.find(sum) == preSum.end())
    {
        preSum[sum] = i;
    }
}