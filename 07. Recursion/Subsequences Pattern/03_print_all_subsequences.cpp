#include <bits/stdc++.h>
using namespace std;
// Function to print all subsets of a given set
void func(int i, vector<int> &temp, vector<int> &nums,
          vector<vector<int>> &ans)
{
    if (i == nums.size())
    {
        ans.push_back(temp); // Store the subset
        return;
    }

    // Take the current element
    temp.push_back(nums[i]);
    func(i + 1, temp, nums, ans);

    // Don't take the current element
    temp.pop_back();
    func(i + 1, temp, nums, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    func(0, temp, nums, ans);
    return ans;
}