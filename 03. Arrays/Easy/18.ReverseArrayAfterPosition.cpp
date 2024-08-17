#include <bits/stdc++.h>
void reverseArray(vector<int> &arr, int m)
{
    // Write your code here
    int range = arr.size() - 1 - m;
    for (int i = m + 1; i < m + 1 + (range / 2); i++)
    {
        swap(arr[i], arr[arr.size() + m - i]);
    }
}