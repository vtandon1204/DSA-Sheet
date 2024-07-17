#include <bits/stdc++.h>
int XOR(int n)
{
    if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n + 1;
    }
    else if (n % 4 == 3)
    {
        return 0;
    }
    else if (n % 4 == 0)
    {
        return n;
    }
}
int findXOR(int l, int r)
{
    // complete the function here
    // int ans = 0;
    // for(int i=l;i<=r;i++){
    //     ans = ans^i;
    // }
    // return ans;

    int xor_r = XOR(r);
    int xor_l = XOR(l - 1);
    return xor_r ^ xor_l;
}