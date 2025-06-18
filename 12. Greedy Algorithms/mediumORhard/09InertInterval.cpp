#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval)
{
    int n = intervals.size();
    int i = 0;
    vector<vector<int>> ans;
    // case 1: no overlapping & before merge interval
    while (i < n && intervals[i][1] > newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    // case 2: overlapping & merge interval
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    // case 3: no overlapping & after merge interval
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}