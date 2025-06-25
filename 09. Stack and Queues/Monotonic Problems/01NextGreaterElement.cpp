#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mpp;
    vector<int> ans;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i]) // pop out smaller elements
            st.pop();

        if (!st.empty()) // store the first greater element
            mpp[nums2[i]] = st.top();
        else // store -1 as there is no greater element
            mpp[nums2[i]] = -1;

        st.push(nums2[i]);
    }
    for (int it : nums1)
    {
        ans.push_back(mpp[it]);
    }
    return ans;
}

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st; // stores indices

    for (int i = n - 1; i >= 0; i--)
    {
        // Pop all smaller or equal elements
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();

        // If stack not empty, top is next greater
        if (!st.empty())
            ans[i] = nums[st.top()];

        // Push current index
        st.push(i);
    }

    return ans;
}
