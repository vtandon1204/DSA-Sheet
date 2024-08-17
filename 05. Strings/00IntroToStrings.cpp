
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getLength(char ch[])
{
    int cnt = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        cnt++;
    }
    return cnt;
}
void reverseString(char ch[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(ch[i], ch[n - i - 1]);
    }
}
#include <bits/stdc++.h>
bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch >= 'Z') || (ch <= '0' && ch >= '9'))
    {
        return 1;
    }
    return 0;
}
char lowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool palindrome(string s)
{
    int st = 0;
    int e = s.length() - 1;
    while (st <= e)
    {
        if (s[st] != s[e])
        {
            return 0;
        }
        else
        {
            st++;
            e--;
        }
    }
    return 1;
}
bool checkPalindrome(string s)
{
    // Write your code here.
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isValid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }
    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = lowerCase(temp[i]);
    }

    return palindrome(temp);
}
int main()
{
    // char name[20];
    // cout << "enter your name " << endl;
    // cin >> name;

    // cout << "your name is " << name << endl;
    // cout << "length of name is " << getLength(name) << endl;

    // reverseString(name, getLength(name));
    // cout << "reversed name is " << name << endl;
    string st = "c1 O$d@eeD o1c";
    if(checkPalindrome(st)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}