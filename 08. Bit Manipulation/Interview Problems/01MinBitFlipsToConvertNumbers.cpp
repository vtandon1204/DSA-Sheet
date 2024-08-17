#include <bits/stdc++.h>
int minBitFlips(int start, int goal)
{
    int ans = start ^ goal; // number of set bits tell the numbers of bit flips
    // counting number of set bits in ans
    int cnt = 0;
    while (ans != 0)
    {
        ans = ans & (ans - 1);
        cnt++;
    }
    return cnt;
}