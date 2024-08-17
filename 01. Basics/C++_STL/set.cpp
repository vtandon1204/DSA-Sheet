#include <iostream>
#include <set>
using namespace std;
int main()
{
    // Set: stores the data in sorted way & unique elements only
    set<int> st;
    st.insert({10, 30, 30, 20, 45});
    for (int i : st)
    {
        cout << i << " ";
    }
    cout << endl;
    auto it = st.find(3); // return element at location 3
    // cout << st.find(3) << endl;
    auto it1 = st.find(6); // if element is not present at this location, then it returns the last element
    st.count(2);           // --> 1 (if present) & 0 (if absent)
    // Time Complecity = O(logN)

    // Multiset: sorted but not unique elements (multiple occurence of elements is allowed)
    multiset<int> ms;
    ms.insert({10, 20, 10, 30, 20});
    for (int num : ms)
    {
        std::cout << num << " ";
    }
    cout << endl;
    ms.erase(10); // erases all the 1's in the set
    for (int num : ms)
    {
        std::cout << num << " ";
    }
    cout << endl;
    ms.erase(ms.find(10)); // erase the 1 at certain iterator
    for (int num : ms)
    {
        std::cout << num << " ";
    }
    cout << endl;
    // ms.erase(ms.find(10), ms.find(10) + 2);

    // Unordered Set: unique but not sorted (randomized order)
    // all operations similar to set works except upper and lower bound
}
