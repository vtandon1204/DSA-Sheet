#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    int ans = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
            cnt--;
        ans = max(ans, cnt);
    }
    return ans;
}