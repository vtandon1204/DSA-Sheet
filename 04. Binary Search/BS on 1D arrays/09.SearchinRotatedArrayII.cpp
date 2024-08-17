#include <bits/stdc++.h>
bool search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[low] == nums[mid] && nums[high] == nums[mid])
        {
            high--;
            low++;
            continue;
        }
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[high] >= target && nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}