#include <bits/stdc++.h>
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    // if (k == n) {
    //     int sum = 0;
    //     for (int p : cardPoints) {
    //         sum += p;
    //     }
    //     return sum;
    // }
    // *****************************************************
    // int points = 0;
    // int lSum = 0;
    // int rSum = 0;
    // for (int i = 0; i < k; i++) {
    //     lSum += cardPoints[i];
    // }
    // int cnt = 0;
    // int j = cardPoints.size() - 1;
    // while (cnt < k) {
    //     cnt++;
    //     rSum += cardPoints[j];
    //     j--;
    // }
    // cout<<lSum<<" and "<<rSum<<endl;
    // points=max(rSum,lSum);
    // *****************************************************
    // int points = 0;
    // int i = 0;
    // int j = cardPoints.size() - 1;
    // int cnt = 0;
    // int temp = INT_MIN;
    // while (cnt < k) {
    //     if (cardPoints[i] == cardPoints[j]) {
    //         if (cardPoints[i + 1] < cardPoints[j - 1]) {
    //             temp = cardPoints[j];
    //             cout << "temp = " << temp << " and " << j << endl;
    //             j--;
    //         } else {
    //             temp = cardPoints[i];
    //             cout << "temp = " << temp << " and " << i << endl;
    //             i++;
    //         }
    //     } else {
    //         temp = max(cardPoints[i], cardPoints[j]);
    //         cout << "temp = " << temp << endl;
    //         if (cardPoints[i + 1] < cardPoints[j - 1] &&
    //             (cardPoints[i] < cardPoints[j - 1])) {
    //             temp = cardPoints[j];
    //             cout << "temp = " << temp << " and " << j << endl;
    //             j--;
    //         } else if ((cardPoints[i + 1] > cardPoints[j - 1]) &&
    //                    (cardPoints[i + 1] > cardPoints[j])) {
    //             temp = cardPoints[i];
    //             cout << "temp = " << temp << " and " << i << endl;
    //             i++;
    //         }
    //     }
    //     points += temp;
    //     cout << "points = " << points << endl;
    //     cnt++;
    // }
    // *****************************************************
    int lSum = 0;
    int rSum = 0;
    int points = 0;
    for (int i = 0; i < k; i++)
    {
        lSum += cardPoints[i];
    }
    points = lSum;
    int j = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lSum -= cardPoints[i];
        rSum += cardPoints[j];
        j--;
        points = max(points, lSum + rSum);
    }
    return points;
}