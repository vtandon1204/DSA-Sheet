#include <bits/stdc++.h>
using namespace std;

vector<string> mapping = {"",
                          "",
                          "abc",
                          "def",
                          "ghi",
                          "jkl",
                          "mno",
                          "pqrs",
                          "tuv",
                          "wxyz"};
void func(int ind, string &digits, string &temp, vector<string> &ans)
{
    if (ind == digits.size())
    {
        if (!temp.empty())
        {
            ans.push_back(temp);
        }
        return;
    }

    string letter = mapping[digits[ind] - '0'];
    for (int i = 0; i < letter.size(); i++)
    {
        temp.push_back(letter[i]);
        func(ind + 1, digits, temp, ans);
        temp.pop_back(); // Backtrack
    }
    // If no letters are present for the digit, we can just call the function without adding anything to temp
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string temp = "";
    func(0, digits, temp, ans);
    return ans;
}