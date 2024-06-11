// Pairs: part of utility library
#include <iostream>
using namespace std;
void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second<<endl;

    pair<int, pair<int, int>> m = {1, {3, 4}};
    cout << m.first << " " << m.second.first << " " << m.second.second<<endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second<<endl;
}
int main(){
    explainPair();
}