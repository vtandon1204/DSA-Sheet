#include <bits/stdc++.h>
int longestOnes(vector<int> &nums, int k)
{
    // int zerocnt = 0;
    // while (zerocnt < k) {
    //     int i = 0;
    //     if (nums[i] == 0) {
    //         nums[i] = 1;
    //         zerocnt++;
    //     }
    //     i++;
    // }
    // int maxx = 0;
    // for (int i = 0; i < nums.size(); i++) {
    //     if (nums[i] == 1) {
    //         maxx = i + 1;
    //     }
    // }
    // return maxx;

    int n = nums.size();
    int start = 0, maxLen = 0, zeroCount = 0;

    for (int end = 0; end < n; ++end)
    {
        if (nums[end] == 0)
        {
            zeroCount++;
        }

        while (zeroCount > k)
        {
            if (nums[start] == 0)
            {
                zeroCount--;
            }
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}