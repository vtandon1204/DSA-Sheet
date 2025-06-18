#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}
void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    reverseStack(s);
    insert(s, x);
}