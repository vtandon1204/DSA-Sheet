#include <bits/stdc++.h>
using namespace std;

// Count all the subsequence of an array whose sum is equal to a given number

int func(int i, int sum, vector<int> &arr, int target)
{
    if (sum > target)
        return 0;
    if (i == arr.size())
    {
        return sum == target ? 1 : 0;
    }

    // sum+=arr[i];
    int left = func(i + 1, sum + arr[i], arr, target);
    // sum-=arr[i];
    int right = func(i + 1, sum, arr, target);
    return left + right;
}
int perfectSum(vector<int> &arr, int target)
{
    return func(0, 0, arr, target);
}