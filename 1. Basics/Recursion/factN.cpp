#include <iostream>
using namespace std;
long long factN(int n)
{
    int fact = 1;
    if (n == 0)
    {
        return 1;
    }
    fact = n * factN(n - 1);
    return fact;
}
int main()
{
    int n;
    cin >> n;
    cout << "the factorial of " << n
         << " is " << factN(n);
    return 0;
}