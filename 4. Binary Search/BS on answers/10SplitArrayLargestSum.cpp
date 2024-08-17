#include <bits/stdc++.h>
int countStudents(vector<int> &arr, int pages)
{
    long long pagesStudent = 0;
    int student = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}
int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    // for (int pages = low; pages <= high; pages++) {
    //     if (countStudents(arr, pages) == m) {
    //         return pages;
    //     }
    // }
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (countStudents(arr, mid) > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int splitArray(vector<int> &nums, int k)
{
    return findPages(nums, nums.size(), k);
}