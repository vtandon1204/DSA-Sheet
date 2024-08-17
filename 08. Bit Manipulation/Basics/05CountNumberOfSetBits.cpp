#include <bits/stdc++.h>
int countSetBits(int n)
{
    // Your logic here
    // int cnt = 0;
    // for (int num = 1; num <= n; num++)
    // {
    //     int i = num;
    //     while (i != 0)
    //     {
    //         i = i & (i - 1);
    //         cnt++;
    //     }
    // }
    // return cnt;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += __builtin_popcount(i);
    }
    return cnt;
}