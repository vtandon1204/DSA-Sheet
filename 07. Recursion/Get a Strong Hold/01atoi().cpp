#include <bits/stdc++.h>
int myAtoi(string s)
{
    int i = 0, result = 0, sign = 1;

    // Step 1: Ignore leading whitespaces
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }

    // Step 2: Handle sign if present
    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // If the next character is not a digit, return 0
    if (i < s.size() && !isdigit(s[i]))
    {
        return 0;
    }

    // Step 3: Convert digits to integer and handle overflow
    while (i < s.size() && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        // Handle potential overflow/underflow before updating result
        if (result > (INT_MAX - digit) / 10)
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}
