#include <bits/stdc++.h>
using namespace std;

int NthRoot(int N, int M)
{
    int low = 1;
    int high = M;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = pow(mid, N);
        if (val == M)
            return mid;
        if (val > M)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}