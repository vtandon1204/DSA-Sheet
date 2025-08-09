#include <bits/stdc++.h>
using namespace std;

int func(const string &s, int start, int end, int n)
{
    // Base condition: when start index exceeds length
    if (start == n)
        return 0;

    // When end index reaches the end of string, move to next start
    if (end == n)
        return func(s, start + 1, start + 1, n);

    // Count current substring + count remaining
    return 1 + func(s, start, end + 1, n);
}

int countSubstring(string s)
{
    return func(s, 0, 0, s.size());
}