#include <bits/stdc++.h>
void merge(int arr[], int l, int m, int r)
{
    // Your code here
    vector<int> temp;
    int i = l;
    int j = m + 1;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= r)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}

void mergeSort(int arr[], int l, int r)
{
    // code here
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}