#include <bits/stdc++.h>
using namespace std;

// Function to generate all combinations of well-formed parentheses
void func(int open, int close, string temp, int n, vector<string> &ans)
{
    if (open == close && open + close == n * 2)
    {
        ans.push_back(temp);
        return;
    }

    if (open < n)
    {
        func(open + 1, close, temp + "(", n, ans);
    }
    if (close < open)
    {
        func(open, close + 1, temp + ")", n, ans);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string temp = "";
    func(0, 0, temp, n, ans);
    return ans;
}