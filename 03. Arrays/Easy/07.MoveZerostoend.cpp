#include <bits/stdc++.h>
void moveZeroes(vector<int> &nums)
{
    int i = 0, j = 0;
    while (i < nums.size() && j < nums.size())
    {
        while (i < nums.size() && nums[i] != 0)
        {
            i++;
        }
        while (j < nums.size() && nums[j] == 0)
        {
            j++;
        }
        if (i < nums.size() && j < nums.size() && i < j)
        {
            swap(nums[i], nums[j]);
        }
        else
        {
            j++;
        }
    }
// **********************************************************************
    int j = -1;
    for (int i = 0; i < nums.size(); i++) // find the index where the first zero occurs in the array
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < nums.size(); i++) // now replace the non-zero numbers with zeros coming ahead of that index 
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}