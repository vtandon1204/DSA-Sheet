#include <bits/stdc++.h>
string postToPre(string post_exp)
{
    int i = 0;
    stack<string> st;
    while (i < post_exp.length())
    {
        if ((post_exp[i] >= 'a' && post_exp[i] <= 'z') || (post_exp[i] >= '1' && post_exp[i] <= '9') || (post_exp[i] >= 'A' && post_exp[i] <= 'Z'))
        {
            st.push(string(1, post_exp[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string temp = post_exp[i] + t2 + t1;
            st.push(temp);
        }
        i++;
    }
    return st.top();
}