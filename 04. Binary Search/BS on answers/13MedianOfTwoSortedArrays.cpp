#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // Brute
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

    // Space Optimization
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;
    int cnt = 0;
    int ind1 = n / 2;
    int ind2 = ind1 - 1;
    int i = 0;
    int j = 0;
    int ind1Val = -1;
    int ind2Val = -1;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == ind1)
                ind1Val = nums1[i];
            if (cnt == ind2)
                ind2Val = nums1[i];
            i++;
            cnt++;
        }
        else
        {
            if (cnt == ind1)
                ind1Val = nums2[j];
            if (cnt == ind2)
                ind2Val = nums2[j];
            j++;
            cnt++;
        }
    }
    while (i < n1)
    {
        if (cnt == ind1)
            ind1Val = nums1[i];
        if (cnt == ind2)
            ind2Val = nums1[i];
        i++;
        cnt++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1Val = nums2[j];
        if (cnt == ind2)
            ind2Val = nums2[j];
        j++;
        cnt++;
    }
    if (n & 1)
    {
        return ind1Val;
    }
    return (double)(ind1Val + ind2Val) / 2;
}

