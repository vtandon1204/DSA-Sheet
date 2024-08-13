#include <bits/stdc++.h>
int totalFruit(vector<int> &fruits)
{
    int left = 0, right = 0, ans = 0;
    int n = fruits.size();
    unordered_map<int, int> freq;

    while (right < n)
    {
        freq[fruits[right]]++;

        while (freq.size() > 2)
        {
            int leftKey = fruits[left];
            freq[leftKey]--;
            if (freq[leftKey] == 0)
            {
                freq.erase(leftKey);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}