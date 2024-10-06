// https://cses.fi/problemset/task/1636/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
 
#define ll              int64_t
#define MOD             1000000007
#define FOR(i, a, b)    for (int i = (a); i < (b); ++i)
#define fastio()        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define arrIn(arr, n)   for(ll i = 0; i < n; i++) cin >> arr[i]
 
ll dp[1000001];
/**************************************************************************************************
 * each index of dp array corresponds to number of ways to build that amount using given coins    *
 * base case is, the value 0 can only be made in one way, using no coins.                         *
 * successive amounts are made by adding one of the given coins to a previously calculated amount *
 *************************************************************************************************/
 
int main(){
    fastio();
    ll n, x; cin >> n >> x;
    ll coins[n]; arrIn(coins, n);
 
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // base case
 
    // in the following filling of the dp array, we traverse through the coins in the outer loop to avoid duplicate permutations
    // such as {1, 2, 1} and {1, 1, 2}. Note that using this method, only {1, 1, 2} will be counted in the resultant dp array
    for (auto c: coins) {
        FOR (i, 1, x+1) { // checking for each successive value, till target sum x
            if (i - c >= 0) // checking number of ways to form sum (i - c) for each coin c
                dp[i] += dp[i-c]; // sum of number of ways to form sum (i - c) for each coin c will be number of ways to form sum i
            dp[i] %= MOD;
        }
    }
 
    cout << dp[x] << endl;
 
    return 0;
}
