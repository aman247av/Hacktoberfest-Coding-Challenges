// Problem Link :- https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        long int maxSum = INT_MIN;
        long int windowSum = 0;
        for (int i = 0; i < K; i++)
        {
            windowSum += Arr[i]; // 600
        }
        maxSum = windowSum;
        for (int i = K; i < Arr.size(); i++)
        {
            // 600 + 300 - 400 = 500
            windowSum += Arr[i] - Arr[i - K];
            maxSum = max(windowSum, maxSum); // 500
        }
        if (K == N)
            maxSum = windowSum;
        return maxSum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        ;
        vector<int> Arr;
        for (int i = 0; i < N; ++i)
        {
            int x;
            cin >> x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K, Arr, N) << endl;
    }
    return 0;
}