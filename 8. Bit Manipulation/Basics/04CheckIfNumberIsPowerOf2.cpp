#include <bits/stdc++.h>
bool isPowerOfTwo(int n)
{
    // for (int i = 0; i <= 30; i++)
    // {
    //     int ans = pow(2, i);
    //     if (ans == n)
    //     {
    //         return true;
    //     }
    // }
    // return false;
    return n > 0 && (n & (n - 1)) == 0;
}