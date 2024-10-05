#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
const ll N = 100000;
const ll M = (ll)1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	bool isprime[n + 1];
	for (int i = 0; i <= n; i++)
	{
		isprime[i] = 1;
	}
	isprime[0] = 0;
	isprime[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!isprime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				isprime[j] = 0;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if (isprime[i])
		{
			cout << i << " ";
		}
	}
	return 0;
}