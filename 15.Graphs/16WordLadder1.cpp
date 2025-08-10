#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    // for(auto it:wordList){
    //     st.insert(it);
    // }
    st.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int step = q.front().second;
        q.pop();
        if (word == endWord)
            return step;
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i]; // the character to be changed
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch; // changing the character
                if (st.find(word) != st.end())
                { // check if it exist in set
                    q.push({word, step + 1});
                    st.erase(word);
                }
            }
            word[i] = original; // reset the word
        }
    }
    return 0;
}