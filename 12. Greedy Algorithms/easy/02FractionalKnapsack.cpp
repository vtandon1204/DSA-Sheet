#include <bits/stdc++.h>
double fractionalKnapsack(int w, Item arr[], int n)
{

    sort(arr, arr + n, [](Item &a, Item &b)
         {
            double frac1 = (double)a.value/a.weight;
            double frac2 = (double)b.value/b.weight;
            return frac1>=frac2; });
    double totalVal = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= w)
        {
            totalVal += arr[i].value;
            w -= arr[i].weight;
        }
        else
        {
            totalVal += (double)((double)arr[i].value / (double)arr[i].weight) * w;
            break;
        }
    }
    return totalVal;
}