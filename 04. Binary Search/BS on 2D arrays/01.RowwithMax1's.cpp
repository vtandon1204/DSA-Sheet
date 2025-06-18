#include <bits/stdc++.h>
using namespace std;

int first1(vector<int> arr, int n)
{
    int low = 0;
    int high = n - 1;
    int first = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == 1)
        {
            first = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return first;
}
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    // int maxx=INT_MIN;
    // int row=0;
    // for(int i=0;i<n;i++){
    //    // row=0;
    //     int cnt=0;
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]==1){
    //             cnt++;
    //         }
    //     }
    //     if(cnt>maxx){
    //         maxx=cnt;
    //         row=i;
    //     }
    // }
    // if(maxx==0){
    //     return -1;
    // }
    // return row ;
    int maxx = INT_MIN;
    int row = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt = m - first1(arr[i], m);
        if (cnt > maxx)
        {
            maxx = cnt;
            row = i;
        }
    }
    if (maxx == 0)
    {
        return -1;
    }
    return row;
}