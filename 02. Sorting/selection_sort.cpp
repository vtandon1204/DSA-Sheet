#include <bits/stdc++.h>

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
}

// Recursive Selection Sort
void selectionSort(int arr[], int n, int i)
{

    if (i == n - 1)
    {
        return;
    }
    int mini = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[mini])
        {
            mini = j;
        }
    }
    swap(arr[mini], arr[i]);

    selectionSort(arr, n, i + 1);
}