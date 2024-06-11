#include <bits/stdc++.h>
vector<int> searchRange(vector<int> &arr, int k)
{
    vector<int> ans(2, -1);
    int n = arr.size();
    int first = -1;
    int last = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            e = mid - 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    s = 0;
    e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            s = mid + 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    ans[0] = first;
    ans[1] = last;
    return ans;
}

int occurence(vector<int> & arr, int n, int x){
    int ans[] = searchRange(arr,x);
    if(ans[0]==-1){
        return 0;
    }
    return (ans[1]-ans[0]+1);
}