#include <bits/stdc++.h>
bool checkKthBit(int n, int k)
{
    // Your code here
    // It can be a one liner logic!! Think of it!!

    // using left shift operator
    int ans = n & (1 << k);
    if (ans != 0)
    {
        return true;
    }
    else
    {
        return false;
    }

    // using right shift operator
    int ans = 1 & (n >> k);
    if (ans == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}