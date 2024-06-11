#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;
    vector<int> nums3;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums3.push_back(nums2[j]);
            j++;
        }
    }
    while (j < n)
    {
        nums3.push_back(nums2[j]);
        j++;
    }
    while (i < m)
    {
        nums3.push_back(nums1[i]);
        i++;
    }
}
void print(vector<int> &num, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    vector<int> nums3 = {0};
    merge(nums1, 6, nums2, 3);
    print(nums3, 6);
}