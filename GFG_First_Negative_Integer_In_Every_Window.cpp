// Problem Statement :- https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        int n = 100;
        long long int arr[100];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    int l = 0, r = 0;
    int negInt = 0;
    deque<long long> temp;
    vector<long long> ans;
    while (r < N)
    {
        if (A[r] < 0)
        {
            temp.push_back(A[r]);
        }
        if (r - l + 1 < K)
            r++;
        else if (r - l + 1 == K)
        {
            if (temp.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(temp.front());
                if (A[l] == temp.front())
                {
                    temp.pop_front();
                }
            }
            l++;
            r++;
        }
    }
    return ans;
}