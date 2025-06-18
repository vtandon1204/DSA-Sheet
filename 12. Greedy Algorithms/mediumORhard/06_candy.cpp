#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    // int n = ratings.size();
    // vector<int> candies(n, 1);

    // // Left to right: make sure each child has more than the left
    // neighbor
    // // if rating is higher
    // for (int i = 1; i < n; ++i) {
    //     if (ratings[i] > ratings[i - 1]) {
    //         candies[i] = candies[i - 1] + 1;
    //     }
    // }

    // // Right to left: make sure each child has more than the right
    // neighbor
    // // if rating is higher
    // for (int i = n - 2; i >= 0; --i) {
    //     if (ratings[i] > ratings[i + 1]) {
    //         candies[i] = max(candies[i], candies[i + 1] + 1);
    //     }
    // }

    // // Sum all candies
    // int total = 0;
    // for (int c : candies) {
    //     total += c;
    // }

    // return total;

    int n = ratings.size();
    if (n == 0)
        return 0;
    int peak;
    int down;
    int total = 1; // First child gets 1 candy
    int i = 1;
    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            total += 1;
            i++;
            continue;
        }
        peak = 1;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            total += peak;
            i++;
        }
        down = 1;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            total += down;
            down++;
            i++;
        }

        if (down > peak)
        {
            total += down - peak;
        }
    }
    return total;
}