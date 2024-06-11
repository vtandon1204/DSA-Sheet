#include <bits/stdc++.h>
void moveZeroes(vector<int> &nums)
{
    // int i,j=0;
    // while(i<nums.size() && j<nums.size()){
    //     if(nums[i]!=0){i++;}
    //     if(nums[j]==0){j++;}
    //     if(i<nums.size() && j<nums.size() && i<j){
    //         swap(nums[i],nums[j]);
    //     }
    // }
    int j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}