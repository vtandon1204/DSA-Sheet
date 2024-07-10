#include <bits/stdc++.h>
void bitManipulation(int num, int i)
{
    // your code here
    // for 1-based indexing
    // if 0 based indexing --> (i-1) changes to (i)
    long get = (num >> (i - 1)) & 1;
    long set = num | (1 << (i - 1));
    long clear = num & (~(1 << (i - 1)));
    cout << get << " " << set << " " << clear << endl;
}