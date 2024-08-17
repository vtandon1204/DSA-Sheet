// Vectors: dynamic arrays; as ability to change the size; traversed using iterators
// vector <object_type> variable_name
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    class std ::vector<int> v(5, 100); // this means this vectors stores '100' 5 times in it i.e {100,100,100,100,100}
    class std ::vector<int> p;         // {}
    class std ::vector<int> q(v);      // copy of v vector
    // to insert elements into vector
    p.insert(p.end(), {20, 10, 15, 6, 7});
    // to traverse the vector elements using for loop
    for (int num : p)
    {
        std::cout << num << " ";
    }
    cout << endl;

    vector<int>::iterator it = p.begin(); // memory address of first element
    cout << *(it) << " " << endl;

    vector<int>::iterator it1 = p.end(); // memory address after the last element
    // vector<int>::iterator it2 = v.rend();   // memory address before first element
    // vector<int>::iterator it3 = v.rbegin(); // memory address of last element

    p.erase(p.begin() + 1, p.begin() + 3); // here the first part is included and the second is excluded
    for (auto i = p.begin(); i != p.end(); i++)
    {
        std::cout << *(i) << " ";
    }
    cout << endl;

    // to insert at a specific location
    p.insert(p.begin() + 1, 30);
    // to traverse the vector elements using for each loop
    for (auto i : p)
    {
        cout << i << " ";
    }
    cout << endl;
}