#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    int n = num.size();
    int ind = -1;
    string ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') & 1)
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
        return "";

    for (int i = 0; i <= ind; i++)
        ans += num[i];

    return ans;
    // return num.substr(0, ind + 1);
}