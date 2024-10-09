#include <bits/stdc++.h>
string postToInfix(string exp)
{
    int i = 0;
    stack<string> st;
    while (i < exp.length())
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '1' && exp[i] <= '9') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            st.push(string(1, exp[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string temp = '(' + t2 + exp[i] + t1 + ')';
            st.push(temp);
        }
        i++;
    }
    return st.top();
}