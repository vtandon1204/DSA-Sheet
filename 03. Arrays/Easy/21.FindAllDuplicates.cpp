#include <bits/stdc++.h>
vector<int> findDuplicates(vector<int>& nums) {
        // vector<int> ans;
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second==2){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;

        vector<int>ans;
        int n=size(nums);
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
    }