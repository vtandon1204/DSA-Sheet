#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n; // size of array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    // creating hash array
    int hash[10] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1; // hash array ke voh-voh index pe 1 count increase kro jo element main array mein hai4
        // hash array stores the frequency of each element of main array at the index equal to value of that element
    }

    // printing main and hash array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << hash[i] << " ";
    }

    // Time Complexity of Map -->
    // storin and fetching: O(logN) (best,worst,average)

    // Time Complexity of Unordered Map (prefered)-->
    // storing and fetching: O(1) (average,best) & O(N) (N:number of elements in map) (worst) (its because of integer collisions)

    return 0;
}