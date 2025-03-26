#include <bits/stdc++.h>
int singleNumber(vector<int> &nums) // single occurence of a number and other occurs twice in the array
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}