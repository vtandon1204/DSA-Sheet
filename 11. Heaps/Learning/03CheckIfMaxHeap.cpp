#include <bits/stdc++.h>
bool isMaxHeap(int arr[], int n)
{
    int i = 0;
    while (i < (n / 2))
    {
        int left = 2 * i + 1;
        int right = 2 * (i + 1);
        if (left < n && arr[left] > arr[i])
        {
            return false;
        }
        else if (right < n && arr[right] > arr[i])
        {
            return false;
        }
        else
        {
            i++;
        }
    }
    return true;
}