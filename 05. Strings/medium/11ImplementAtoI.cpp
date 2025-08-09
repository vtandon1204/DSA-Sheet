#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int sign = 1;
    int ans = 0;

    while (i < s.size() && s[i] == ' ')
        i++;

    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    if (i < s.size() && !isdigit(s[i]))
        return 0;

    while (i < s.size() && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        ans = ans * 10 + digit;
        i++;
    }

    return sign * ans;
}