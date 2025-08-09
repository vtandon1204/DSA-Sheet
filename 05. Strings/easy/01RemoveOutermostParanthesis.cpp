#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    string ans = "";
    int n = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (n > 0)
                ans += s[i];
            n++;
        }
        else
        {
            n--;
            if (n > 0)
                ans += s[i];
        }
    }
    return ans;
}