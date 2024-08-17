#include <bits/stdc++.h>
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    double med = 0;
    vector<double> merge;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            merge.push_back(nums1[i]);
            i++;
        }
        else
        {
            merge.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size())
    {
        merge.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        merge.push_back(nums2[j]);
        j++;
    }
    if (merge.size() & 1)
    {
        int s = 0;
        int e = merge.size() - 1;
        int mid = s + (e - s) / 2;
        med = merge[mid];
    }
    else
    {
        int s = 0;
        int e = merge.size() - 1;
        int mid1 = s + (e - s) / 2;
        int mid2 = mid1 + 1;
        med = (merge[mid1] + merge[mid2]) / 2;
    }
    return med;
}