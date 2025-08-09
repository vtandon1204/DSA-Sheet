#include <bits/stdc++.h>
using namespace std;

int totalFruits(vector<int> &arr)
{
    // optimised *******
    int left = 0;
    int right = 0;
    int maxLen = 0;
    unordered_map<int, int> mpp;
    while (right < arr.size())
    {
        mpp[arr[right]]++;
        if (mpp.size() > 2)
        {
            mpp[arr[left]]--;
            if (mpp[arr[left]] == 0)
                mpp.erase(arr[left]);
            left++;
        }
        else
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;

    // better *******
    // int left = 0, right = 0, ans = 0;
    // int n = arr.size();
    // unordered_map<int, int> freq;

    // while (right < n) {
    //     freq[arr[right]]++;

    //     while (freq.size() > 2) {
    //         int leftKey = arr[left];
    //         freq[leftKey]--;
    //         if (freq[leftKey] == 0) {
    //             freq.erase(leftKey);
    //         }
    //         left++;
    //     }
    //     ans = max(ans, right - left + 1);
    //     right++;
    // }
    // return ans;

    // brute ******
    // int maxLen = 0;
    // for(int i=0;i<arr.size();i++){
    //     set<int> s;
    //     for(int j=i;j<arr.size();j++){
    //         s.insert(arr[j]);
    //         if(s.size()<=2){
    //             maxLen = max(maxLen,j-i+1);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
    // return maxLen;
}