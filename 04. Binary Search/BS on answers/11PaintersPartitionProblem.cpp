#include <bits/stdc++.h>
int accumulate(vector<int> arr)
{
    int sum = 0;
    for (int i : arr)
    {
        sum += i;
    }
    return sum;
}
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
int findPages(vector<int> arr, int n, int m)
{
    // Write your code here.
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr);

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
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    return findPages(boards, boards.size(), k);
    // return ans;
}