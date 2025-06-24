#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    // Brute
    vector<int> arr;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            arr.push_back(arr1[i++]);
        else
            arr.push_back(arr2[j++]);
    }
    while (i < n)
    {
        arr.push_back(arr1[i++]);
    }

    while (j < m)
    {
        arr.push_back(arr2[j++]);
    }
    return arr[k - 1];

    // Space Optimization
    int i = 0;
    int j = 0;
    int ans;
    while (i < n && j < m)
    {
        if (k == 0)
            break;

        if (arr1[i] < arr2[j])
        {
            ans = arr1[i++];
            k--;
        }
        else
        {
            ans = arr2[j++];
            k--;
        }
    }
    while (i < n)
    {
        if (k == 0)
            break;
        ans = arr1[i++];
    }

    while (j < m)
    {
        if (k == 0)
            break;
        ans = arr2[j++];
    }
    return ans;
}