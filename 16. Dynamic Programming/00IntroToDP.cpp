#include <bits/stdc++.h>
using namespace std;

// 1. Top-Down approach --> recursion + memoisation
// -> create space: vector<int> dp(n+1, -1);
// -> store before returning: dp[n] = f(n-1)+f(n-2);
// -> check if already done: if(dp[n]!=-1) return dp[n];

int fib_memo(int n)
{
    vector<int> dp(n + 1, -1);
    if (n <= 1)
        return n; // base case
    if (dp[n] != -1)
        return dp[n];                          // check memoisation
    dp[n] = fib_memo(n - 1) + fib_memo(n - 2); // store result
    return dp[n];
}
// 2. Bottom-Up approach --> tabulation
// -> create space: vector<int> dp(n+1, 0);
// -> base case: dp[0] = 0; dp[1] = 1;
// -> fill the dp array iteratively: for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
// -> return the value: return dp[n];

int fib_tab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = 1; // base case
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2]; // fill the dp array iteratively
    return dp[n];                      // return the value
}

// 3. Space Optimisation
// -> create two variables: int prev2 = 0, prev1 = 1;
// -> iterate from 2 to n: for(int i=2; i<=n; i++) { int curr = prev1 + prev2; prev2 = prev1; prev1 = curr; }
// -> return the value: return prev1;

int fib_space_opt(int n)
{
    if (n <= 1)
        return n;             // base case
    int prev2 = 0, prev1 = 1; // space optimisation
    int curr;
    for (int i = 2; i < n; i++)
    {
        curr = prev1 + prev2; // calculate current value
        prev2 = prev1;            // update previous values
        prev1 = curr;
    }
    return curr; // return the value
}
int main()
{
    int n;
    cin >> n;
    cout << fib_space_opt(n) << endl; // Call the Fibonacci function
    return 0;
}