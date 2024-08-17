#include <bits/stdc++.h>
int divide(int dividend, int divisor)
{
    if (dividend == divisor)
    {
        return 1;
    }
    bool sign = true;
    if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0))
    {
        sign = false;
    }
    long num = abs(dividend);
    long den = abs(divisor);
    long ans = 0;
    while (num >= den)
    {
        int cnt = 0;
        while (num >= (den << (cnt + 1)))
        {
            cnt++;
        }
        ans += 1 << cnt;
        num -= (den << cnt);
    }
    if (ans == (1 << 31) && sign)
    {
        return INT_MAX;
    }
    if (ans == (1 << 31) && !sign)
    {
        return INT_MIN;
    }
    return sign ? ans : -ans;
}