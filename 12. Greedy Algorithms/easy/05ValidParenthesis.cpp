#include <bits/stdc++.h>
// bool check(string s, int index, int cnt)
// {
//     if (cnt < 0)
//     {
//         return false;
//     }
//     if (index == s.size())
//     {
//         return (cnt == 0);
//     }
//     if (s[index] == '(')
//     {
//         return check(s, index + 1, cnt + 1);
//     }
//     if (s[index] == ')')
//     {
//         return check(s, index + 1, cnt - 1);
//     }
//     return (check(s, index + 1, cnt + 1) || check(s, index + 1, cnt - 1) ||
//             check(s, index + 1, cnt));
// }
// bool checkValidString(string s) { return check(s, 0, 0); }



