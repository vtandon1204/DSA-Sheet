#include <bits/stdc++.h>
using namespace std;
// Generate all Binary Strings of length n such that no two consecutive bits are 1
vector<string> generateBinaryStrings(int num)
{
    if (num == 0)
        return {""};
    if (num == 1)
        return {"0", "1"};

    vector<string> ans;
    for (string s : generateBinaryStrings(num - 1))
    {
        ans.push_back(s + "0");
        if (s[s.length() - 1] != '1')
        {
            ans.push_back(s + "1");
        }
    }
    return ans;
}