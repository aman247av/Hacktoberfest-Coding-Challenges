// Problem Link: https://codeforces.com/problemset/problem/2011/B

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // For faster input and output

    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Size of the array
        cin >> n;

        cout << "1 "; // Print '1'
        for (int i = n; i >= 2; --i) { // Loop from n down to 2
            cout << i << " "; // Print current number
        }
        cout << '\n'; // New line after each test case
    }

    return 0;
}
