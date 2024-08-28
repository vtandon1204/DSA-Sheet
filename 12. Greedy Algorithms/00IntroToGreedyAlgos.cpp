#include <bits/stdc++.h>
// N meetings in One Room
int maxMeetings(int n, int start[], int end[])
{
    vector<pair<int, int>> time;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        time.push_back(p);
    }
    sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    int cnt = 1;
    int ansEnd = time[0].second;

    for (int i = 1; i < n; i++)
    {
        if (time[i].first > ansEnd)
        {
            cnt++;
            ansEnd = time[i].second;
        }
    }
    return cnt;
}

// Maximum Meetings in One Room

// Activity Selection Problem
int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> time;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        time.push_back(p);
    }
    sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    int cnt = 1;
    int ansEnd = time[0].second;

    for (int i = 1; i < n; i++)
    {
        if (time[i].first > ansEnd)
        {
            cnt++;
            ansEnd = time[i].second;
        }
    }
    return cnt;
}

// Shop in Candy Store
vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);
    int min_amt = 0;
    int buy = 0;
    int freee = N - 1;
    while (buy <= freee)
    {
        min_amt += candies[buy];
        buy++;
        freee -= K;
    }
    buy = N - 1;
    freee = 0;
    int max_amt = 0;
    while (freee <= buy)
    {
        max_amt += candies[buy];
        buy--;
        freee += K;
    }
    vector<int> ans;
    ans.push_back(min_amt);
    ans.push_back(max_amt);
    return ans;
}

// Reverse Words in given String
string reverseWords(string S)
{
    string ans = "";
    string temp = "";
    for (int i = S.length() - 1; i >= 0; i--)
    {
        if (S[i] == '.')
        {
            reverse(temp.begin(), temp.end());
            ans = ans + temp;
            ans.push_back('.');
            temp = "";
        }
        else
        {
            temp.push_back(S[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    ans = ans + temp;
    return ans;
}

// Check if it is possible to survive on Island

// Chocolate Distribution Problem
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    int i = 0;
    // int j = m-1;
    int mini = INT_MAX;
    while (m + i - 1 < a.size())
    {
        int diff = a[m + i - 1] - a[i];
        mini = min(mini, diff);
        i++;
        // j++;
    }
    return mini;
}

// Minimum Cost of Ropes
long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;
    while (pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        cost += (first + second);

        pq.push(first + second);
    }
    return cost;
}

// Huffman Encoding

// Fractional Knapsack Problem
double fractionalKnapsack(int w, Item arr[], int n)
{

    sort(arr, arr + n, [](Item &a, Item &b)
         {
            double frac1 = (double)a.value/a.weight;
            double frac2 = (double)b.value/b.weight;
            return frac1>=frac2; });
    double totalVal = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= w)
        {
            totalVal += arr[i].value;
            w -= arr[i].weight;
        }
        else
        {
            totalVal += (double)((double)arr[i].value / (double)arr[i].weight) * w;
            break;
        }
    }
    return totalVal;
}

// Job Sequencing Problem
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, [](Job a, Job b)
         { return a.profit > b.profit; });

    int maxDeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> schedule(maxDeadline + 1, -1);

    int jobsDone = 0;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int currProfit = arr[i].profit;
        int currDead = arr[i].dead;
        int currId = arr[i].id;

        for (int k = currDead; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                jobsDone++;
                maxProfit += currProfit;
                schedule[k] = currId;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(jobsDone);
    ans.push_back(maxProfit);
    return ans;
}