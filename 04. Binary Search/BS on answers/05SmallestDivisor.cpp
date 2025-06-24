#include <bits/stdc++.h>
using namespace std;

long long sumAfterDivision(vector<int> &nums, long long x)
{
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % x == 0)
            sum += (long long)(nums[i]) / x;
        else
            sum += ((long long)(nums[i]) / x) + 1;
    }
    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n == threshold)
    {
        return *max_element(nums.begin(), nums.end());
    }
    long long low = 1;
    long long high = *max_element(nums.begin(), nums.end());

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long sum = sumAfterDivision(nums, mid);
        if (sum > threshold)
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