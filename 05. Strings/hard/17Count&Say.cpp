#include <bits/stdc++.h>
using namespace std;

string func(string s)
{
    if (s.size() == 0)
        return "1";

    string ans = "";
    int len = s.size();

    for (int i = 0; i < len; i++)
    {
        int cnt = 1;

        while (i < len - 1 && s[i] == s[i + 1])
        {
            i++;
            cnt++;
        }
        ans += to_string(cnt);
        ans += s[i];
    }
    return ans;
}
string countAndSay(int n)
{
    string ans = "";
    while (n--)
        ans = func(ans);

    return ans;
}