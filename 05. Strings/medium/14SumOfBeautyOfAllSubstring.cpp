#include <bits/stdc++.h>
using namespace std;

int beautySum(string s)
{
    int totalBeauty = 0;

    for (int i = 0; i < s.size(); i++)
    {
        vector<int> freq(26, 0); // Frequency array for 'a' to 'z'
        int maxFreq = 0;

        for (int j = i; j < s.size(); j++)
        {
            // Update frequency of current character
            int charIndex = s[j] - 'a';
            freq[charIndex]++;

            // Update maxFreq dynamically
            maxFreq = max(maxFreq, freq[charIndex]);

            // Find minFreq (non-zero frequencies only)
            int minFreq = INT_MAX;
            for (int k = 0; k < 26; k++)
                if (freq[k] > 0)
                    minFreq = min(minFreq, freq[k]);

            // Add the beauty of the current substring
            totalBeauty += (maxFreq - minFreq);
        }
    }

    return totalBeauty;
}