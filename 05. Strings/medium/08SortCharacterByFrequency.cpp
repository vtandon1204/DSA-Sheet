#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++)
        freq[s[i]]++;

    vector<pair<char, int>> freqVector(freq.begin(), freq.end());
    sort(freqVector.begin(), freqVector.end(), [](const auto &a, const auto &b)
         { return a.second > b.second; });

    string ans;
    for (const auto &it : freqVector)
        ans += string(it.second, it.first);

    return ans;
}