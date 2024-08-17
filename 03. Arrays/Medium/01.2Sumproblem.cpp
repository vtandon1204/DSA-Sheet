#include <bits/stdc++.h>
vector<int> twoSum(vector<int> &nums, int target)
{
    //     vector<int> ans;
    //     vector<int> arr;
    //     copy(nums.begin(),nums.end(),begin(arr))
    //     sort(arr.begin(),arr.end());
    //   int n=nums.size();
    //     int left = 0,right = n-1;
    //     while(left<right){
    //         int sum=arr[right]+arr[left];
    //         if(sum==target){
    //             ans.push_back(left);
    //             ans.push_back(right);
    //             return ans;
    //         }
    //         else if (sum<target){
    //             left++;
    //         }
    //         else {
    //             right--;
    //         }
    //     }
    //     return {};
    // }

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int need = target - num;
        if (mp.find(need) != mp.end())
        {
            return {mp[need], i};
        }
        mp[num] = i;
    }
    return {};
}