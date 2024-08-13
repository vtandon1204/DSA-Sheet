#include <bits/stdc++.h>
int numberOfSubarrays(vector<int> &nums, int k)
{
    int count = 0;
    int odd_cnt = 0;
    vector<int> cnt(nums.size() + 1, 0);
    cnt[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 1)
        {
            odd_cnt++;
        }
        cnt[odd_cnt]++;
        // if odd_cnt exceeds k and then to check if there's another nice
        // subarray
        if (odd_cnt - k >= 0)
            count += cnt[odd_cnt - k];
    }
    return count;
}