#include <iostream>
using namespace std;
long long sumN(int n)
{
    int sum = 0;
    if (n == 0)
    {
        return 0;
    }
    sum = n + sumN(n - 1);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << "the sum of first " << n
         << " numbers is " << sumN(n);
    return 0;
}