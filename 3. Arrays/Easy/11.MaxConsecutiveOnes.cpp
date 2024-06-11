#include <bits/stdc++.h>
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0, maxx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            // maxx = max(cnt, maxx);
        }
        else
        {
            maxx = max(cnt, maxx);
            cnt = 0;
        }
    }
    maxx = max(cnt, maxx);
    return maxx;
}