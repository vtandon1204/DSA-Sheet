#include <bits/stdc++.h>
void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

// Recursive Approach
void bubbleSort(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSort(arr, n - 1);
}