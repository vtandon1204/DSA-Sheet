#include <bits/stdc++.h>
// bool check(string s, int index, int cnt) {
//     if (cnt < 0) {
//         return false;
//     }
//     if (index == s.size()) {
//         return (cnt == 0);
//     }
//     if (s[index] == '(') {
//         return check(s, index + 1, cnt + 1);
//     }
//     if (s[index] == ')') {
//         return check(s, index + 1, cnt - 1);
//     }
//     return (check(s, index + 1, cnt + 1) || check(s, index + 1, cnt - 1)
//     ||
//             check(s, index + 1, cnt));
// }
// bool checkValidString(string s) { return check(s, 0, 0); }
bool checkValidString(string s)
{
    int minn = 0;
    int maxx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            minn += 1;
            maxx += 1;
        }
        else if (s[i] == ')')
        {
            minn -= 1;
            maxx -= 1;
        }
        else
        {
            minn -= 1;
            maxx += 1;
        }
        if (minn < 0)
        {
            minn = 0;
        }
        if (maxx < 0)
        {
            return false;
        }
    }
    return (minn == 0);
}
