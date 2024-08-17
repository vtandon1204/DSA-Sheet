#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    // Write your code here.
    int low = 1;
    int high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long val = mid * mid;
        if (val <= (long long)(n))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
double morePrecision(int n, int precision, int tempSol)
{
    double ans = tempSol;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    // Write your code here.
    int low = 1;
    int high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long val = mid * mid;
        if (val <= (long long)(n))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
double morePrecision(int n, int precision, int tempSol)
{
    int ans = tempSol;
    int factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (int j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter the number" << endl;
    cin >> n;
    int tempSol = floorSqrt(n);
    int ans = morePrecision(n, 3, tempSol);
    cout << "square root of " << n << " is " << ans << endl;
    return 0;
}
;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter the number" << endl;
    cin >> n;
    int tempSol = floorSqrt(n);
    double ans = morePrecision(n, 3, tempSol);
    cout << "square root of " << n << " is " << ans << endl;
    // cout << tempSol;
    return 0;
}
