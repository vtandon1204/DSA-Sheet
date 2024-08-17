#include <bits/stdc++.h>
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int mini = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    // for(int i=0;i<prices.size();i++){
    //     for(int j=i+1;j<prices.size();j++){
    //         int cost=prices[j]-prices[i];
    //     profit=max(cost,profit);
    //     }
    // }
    return profit;
}