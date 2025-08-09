#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string ans = "";
    
    // for traversing all chars of first word
    for (int i = 0; i < strs[0].length(); i++)
    {
        char ch = strs[0][i];
        bool match = true;
        // for comparing ch with rest of the words
        for (int j = 1; j < n; j++)
        {
            // not match
            if (strs[j].size() < i || ch != strs[j][i])
            {
                match = false;
                break;
            }
        }
        if (!match)
            break;
        else
            ans += ch;
    }
    return ans;
}