#include <bits/stdc++.h>
pair<int, int> get(int a, int b)
{
    // complete the function here
    pair<int, int> p;
    // using temp
    int temp = a;
    a = b;
    b = temp;

    // using maths
    a = a + b;
    b = a - b;
    a = a - b;

    // using XOR
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    p.first = a;
    p.second = b;
    return p;
}