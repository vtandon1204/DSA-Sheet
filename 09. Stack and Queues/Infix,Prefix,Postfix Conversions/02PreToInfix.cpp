#include <bits/stdc++.h>
using namespace std;
string preToInfix(string pre_exp)
{
    int i = pre_exp.length() - 1;
    stack<string> st;
    while (i >= 0)
    {
        if ((pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= '1' && pre_exp[i] <= '9') || (pre_exp[i] >= 'A' && pre_exp[i] <= 'Z'))
        {
            st.push(string(1, pre_exp[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string temp = '(' + t1 + pre_exp[i] + t2 + ')';
            st.push(temp);
        }
        i--;
    }
    return st.top();
}