#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string ans = "";
    string temp = "";
    bool firstWord = true;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (!temp.empty())
            {
                if (!firstWord)
                    ans += ' ';
                for (int j = temp.size() - 1; j >= 0; j--)
                    ans += temp[j];

                temp = "";
                firstWord = false;
            }
        }
        else
        {
            temp += s[i];
        }
    }
    if (!temp.empty())
    {
        if (!firstWord)
            ans += ' ';
        for (int j = temp.size() - 1; j >= 0; j--)
            ans += temp[j];
    }
    return ans;
}
