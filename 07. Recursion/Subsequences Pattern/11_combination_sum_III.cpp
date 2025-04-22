#include <bits/stdc++.h>
using namespace std;
void func(int ind, int n, int k, vector<int> &temp, vector<vector<int>> &ans)
{
    if (k == 0) // If we have selected k numbers
    {
        if (n == 0) // If the sum of selected numbers is equal to n
            ans.push_back(temp);
        return;
    }
    for (int i = ind; i <= 9; i++)
    {
        temp.push_back(i); // Select the current number
        func(i + 1, n - i, k - 1, temp, ans); // Recur for the next number
        // Backtrack
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    func(1, n, k, temp, ans);
    return ans;
}