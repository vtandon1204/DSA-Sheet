#include <bits/stdc++.h>
// Given an integer array nums where every element appears three times except for one, which appears exactly once. 
// Find the single element and return it.
int singleNumber(vector<int> &nums)
{
    // unordered_map <int,int> mp;
    // int ans;
    // for(int i=0;i<nums.size();i++){
    //     mp[nums[i]]++;
    // }
    // for(auto it:mp){
    //     if(it.second == 1){
    //         ans = it.first;
    //     }
    // }
    // return ans;

    sort(nums.begin(), nums.end());
    int ans;
    bool flag = false;
    for (int i = 1; i < nums.size(); i += 3)
    {
        if (nums[i] != nums[i - 1])
        {
            return nums[i - 1];
        }
    }
    return nums[nums.size() - 1];
}